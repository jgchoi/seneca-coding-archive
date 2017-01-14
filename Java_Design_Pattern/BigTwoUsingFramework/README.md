## Documentation for Assignment 3
### Code for Assignment 3
* Ravideep's code in branch: RavideepDhupia (CrazyEights implementation using framework from A-2)
* Jung's code in branch: JungGeonChoi (BigTwo implementation using framework from A-2)
* Complete framework in Master branch -  exactly common to both implementations

### Changes Made on the Framework
| Class Name | Method Name | Changes Made |Modified By|
|---|---|---|---|
|Card|getRank|method added|Jung|
|Card|getSuite|method added|Jung|
|CardsStack|getAllCards|method added|Jung|
|GameComposite and GameLeaf|run method|Logic Error.. Missing '!' for isGameCompleted Check|Jung|
|GameEngineer|configureGame method|Order changed.. Error in setDeck by having 0 number of players|Jung|
|Card|getRank and getSuite|return type changed to int|Jung|
|Game|setDeck|Logic for calculating number of decks required fixed.|Jung|
|Game|setPlayer|Message for user is changed. (No change in logic)|Jung|
|Game|setHighestRank|Setting highest rank wasn't implemented|Jung|
|GameComposite|getGameComponent|Method added|Jung|
|Card|getRankFaceValue, get rank and suite String values, card & suite comparison methods |methods added for better UI and code readability (No logic changes)|R.D|
|Game|setPlayers | Logic modified to 1) randomize players order 2) differentiate between human and computer players 3) bring 1 line of code outside the loop, which was wrongly inside the loop earlier |R.D|
***
# Card Game Framework
Game chosen for implimentation demo: Go Fish!
## UML Diagrams
* UML Diagram for Jung's A1 program: [classDiagrams/ClassDigram(Jung).png](classDiagrams/ClassDigram(Jung).png)
* UML Diagram for Ravideep's A1 program: [classDiagrams/ClassDiagram(Ravideep).jpg](classDiagrams/ClassDiagram(Ravideep).jpg)
* UML Diagram for Framework A2 (Initial Plan) (Initial Design using StarUML): [classDigrams/FrameworkDiagram.mdj](classDiagrams/FrameworkDiagram.mdj)
* UML Diagram for **Framework A2 (Final Class Diagram)**(PNG from actual Java project): [classDiagrams/FrameworkClassDiagram.png](classDiagrams/FrameworkClassDiagram.png)

##Design Patterns Used
| Design Pattern Used  | Class(es) Involved   | Explanation  | Benefits |
|---|---|---|---|
| Singleton  | Game | Game class is core class that contains all the game data, parameters. Any class can get instance of unique Game instance using static method.   | *Ensures Game class has only one instance, and that the Game instance is easily accessible. *Allows Game instance to be extensible by sub-classing. *Encapsulatin of the sole Game instance. *Allows controlled access to the Game instance.|
| Strategy  | MoveStrategy, GoFishHumanMove, GoFishComputerMove  |  Player object stores reference to MoveStrategy. At the creation time, the Game class sets the player as computer or human by setting the correct strategy for the move. When player calls makeMove(), correct move method is called | *All related algorithms, which vary with the type of card game, can be grouped under the MoveStrategy interface umbrella. *Better alternative than creating sub-classes for the framework. *Different variants of moves related algorithm can be implemented with ease. *Easier to switch between moves related algorithms (Humana and Computer)|
| Composite | GameComponent, GameComposite, GameLeaf, GoFishTurn, GoFishGame | Depends on the types of game, it is possible for the game to have multiple layers. For example, Big Two has 4 layers (BigTwo, Round, Hand, Turn, new deck needs to be created and new set of cards need to be distributed. To handle the differences, composite pattern that stores different components (layer) of game stages is created. At the client level, only thing required is to call run() from the outermost game component.| *Pattern implemented handles the recursive composition, client doesn't have to make the distinction. *Client can ignore the difference composition of Game layers and individual game with single layer.|
| Factory Method  | PlayerFactory, GoFishPlayerFactory  | Because framework decides which kind of Player class needs to be instantiated, factory for Players is created. PlayerFactory has one method that lets its subclass implement the method that returns appropriate subclass of Player. | *Encapsulates knowledge of which Player subclass is to be created, depending upon the type of Game being played. *Solves the issue, that the class cannot anticipate which Game's player class will have to be created. *Provides hooks for Player subclasses. *More flexible alternative to creating Player objects directly. |
| Builder  | GameEngineer, ConfigurationBuilder, GoFishConfiguration, Game  | Builder pattern is used to create Game objects which will contain all information that define a particular game. GameEngineer will be used to access the builder class, build the game and get an instance of the game. ConcreteBuilder class for each game type will implement functionality for the steps required to build a game. It will also set up implementations for pre game and post game requirements.  | *Client doesn't need to know how Games are created. GameEngineer will construct the game. *configureGame method in GameEngineer allows us to order the build steps as per out needs. Ensures that correct order is followed. *We can build different Game objects using the same construction process. |
|Template | GameComposite, GameLeaf, Game| the run() method in related classes are pre structured with abstract methods such as: call before run, after run, before while look start, and after while loop starts. It gives the structure for the developer to add logic. | *Subclasses are able to give concrete behaviours to the abstract methods mentioned in explanation, with Template pattern we can fix their ordering and vary the steps as per their respective requirements. *Avoids unnecessary code duplication.|
