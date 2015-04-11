<?php 
include "myClasses.php";
$string = array(	"<a href='testMenu.php'>testMenu.php::</a>",
						"<a href='testDB.php'>testDB.php::</a>",
						"<a href='protected2.php'>protected2.php::</a>",
						"<a href='logout.php'>logout.php::</a>",
						"<a href='protectedstuff.php'>protectedstuff.php::</a>");
$menu = new Menu($string);
$menu->display();

?>
		<table border='1'>
			<tr>
				<th>id</th>
				<th>itemName</th>
				<th>description</th>
				<th>supplierCode</th>
				<th>cost</th>
				<th>price</th>
				<th>onHand</th>
				<th>reorderPoint</th>
				<th>backOrder</th>
				<th>deleted</th>
				<th>link</th>
			</tr>
			<?php
				
				// Get all records now in DB		
				$dbObject = new DBLink();
				
				$sql_query = "SELECT * from inventory";
				$result = $dbObject->query($sql_query);
				?>
			<h1>test empty result </h1>
			<p><?php if($dbObject->emptyResult()) 
							print "true";
							else 
							print "false";?></p><?php 
				while($row = mysqli_fetch_assoc($result)){
			?>
			<tr>
				<td><?php print $row['id']; ?></td>
				<td><?php print $row['itemName']; ?></td>
				<td><?php print $row['description']; ?></td>
				<td><?php print $row['supplierCode']; ?></td>
				<td><?php print $row['cost']; ?></td>
				<td><?php print $row['price']; ?></td>
				<td><?php print $row['onHand']; ?></td>
				<td><?php print $row['reorderPoint']; ?></td>
				<td><?php print $row['backOrder']; ?></td>
				<td><?php print $row['deleted']; ?></td>
				<td><a href="delete.php?<?php if ($row['deleted'] == "y") print 'id='.$row['id'].'&deleted=N'; else print 'id='.$row['id'].'&deleted=Y'; ?>"><?php if ($row['deleted'] == "y") print 'Restore'; else print 'Delete'; ?></a></td>
			</tr>
			<?php 
			}
			?>
			
		</table>
	</body>
</html>