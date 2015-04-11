<html>
	<head><title>View.php</title></head>
	<body>
		<a href="add.php">Go to 'Add.php'</a>
		<hr>
		<br>
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
				include('common.php');
				// Get all records now in DB		
				$sql_query = "SELECT * from inventory";
				//Run our sql query
				$result = mysqli_query($link, $sql_query) or die('query failed'. mysqli_error($link));
				
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