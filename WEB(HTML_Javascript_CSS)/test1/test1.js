
var Sales = {
            name: "",
            amount: 0
          };

	  
var max = 0;
var maxName = "No valid input";
var salesPerson = Object.create(Sales);
salesPerson.name = prompt("Enter sales Person's name: ", "");
salesPerson.amount = parseFloat(prompt("Enter the sales amount: ", 0));

while (salesPerson.amount >=0)
{
      if (salesPerson.amount > max)
      {
         max = salesPerson.amount;
         maxName = salesPerson.name;
      }
      salesPerson.name = prompt("Enter sales Person's name: ", "");
      salesPerson.amount = parseFloat(prompt("Enter the sales amount: ", 0));
}

alert(maxName + " has the largest sale of $" + max + "\n");


//holytrinity school
