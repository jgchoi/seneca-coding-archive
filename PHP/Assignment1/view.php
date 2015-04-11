<?php
/*
 * Course : BTI320B
 * Name : Jung Geon Choi
 * Date Submitted : Oct. 14, 2014
 *
 * Student Declaration
 * I/we declare that the attached assignment is my/our own work in accordance with Seneca Academic Policy. No part of this assignment has been copied manually or electronically from any other source (including web sites) or distributed to other students.
 * Name Jung Geon Choi
 * Student ID 025651134
 *
*/
	//Common library
	include "a1.lib";
	
	//Header + Menu
	writeHeader();
	writeMenu();
?>
<!-- Table -->
	<!-- Table header -->
	<table border="1">
		<tr >
			<th>Item ID</th>
			<th>Product Name</th>
			<th>Description</th>
			<th>Supplier Code</th>
			<th>Cost</th>
			<th>Price</th>
			<th>Current Stock</th>
			<th>Reorder Point</th>
			<th>Back Order</th>
			<th>Delete/Restore</th>
		</tr>
		<!-- Table header end -->
		<?php
			//Link DB
			$link = dbConnection();
			
			// Get all records now in DB		
			$sql_query = "SELECT * from inventory";
			//Run our sql query
			$result = mysqli_query($link, $sql_query) or die('query failed'. mysqli_error($link));
			$i = 1; // for color alteration
			while($row = mysqli_fetch_assoc($result))
			{
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
						<td>	<a href="delete.php?<?php if ($row['deleted'] == "y") print 'id='.$row['id'].'&deleted=N'; else print 'id='.$row['id'].'&deleted=Y'; //dynamic link for delete/restore?>">
								<?php if ($row['deleted'] == "y") print 'Restore'; else print 'Delete'; ?>
								</a>
						</td>
					</tr>
				<?php 
			}
			
			//DB close;
			mysqli_close($link);
		?>
		
	</table>

<?php
	//write footer
	writeFooter();
?>