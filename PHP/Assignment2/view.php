<?php
	//Include library
	include "a1.lib";

	//HTTPS control
	$https_control = new Https_control();
	$https_control->check_https();
	
	//session control
	$session_control = new Session_control();
	$session_control->session_user();
	
	//Create DBLink Object
	$db = new DBLink();
	
	//POST (search requested)
	if($_POST)
	{
		//set keyword to session
		$_SESSION['keyword'] = $_POST['keyword'];
	}
	
	//GET check clear
	if($_GET)
	{
		if(isset($_GET['clear']))
		{
			//View all requested, remove keyword
			$_SESSION['keyword'] = "";
		}
	}
		
	
	//Get all records now in DB		
	$sql_query = "SELECT * FROM inventory ";
	
	//search keyword addition
	$sql_query .= " WHERE description like \"%".$_SESSION['keyword']."%\"";
	
	//order addition
	if($_GET)
	{
		if(isset($_GET['order_by']))
		{
			//validate order_by input
			$valid_list = array("id","itemName","description","supplierCode","cost","price","onHand","reorderPoint", "backOrder", "deleted");

			foreach($valid_list as $item)
			{	
				if($_GET['order_by']==$item)
				{	
					//set query by get only if the item is valid
					$sql_query .= " ORDER BY ".$_GET['order_by'].";";
					//set cookie
					$cookie_control = new Cookie_control();
					$cookie_control->set_keyword($_GET['order_by']);		
				}
			}		
		}
		else
		{
			$sql_query .= " ORDER BY ".$_COOKIE['order_by'].";";
		}
	}		
	else
	{
		$sql_query .= " ORDER BY ".$_COOKIE['order_by'].";";
	}
	
	
	
	//Run our sql query
	$result = $db->query($sql_query);

	//Header
	$header_and_footer = new HeaderAndFooter();
	$header_and_footer->displayHeader();
	
	//menu
	$menu = new Menu();
	$menu->display($_SESSION['keyword'], $_SESSION['username'],$_SESSION['role']);
	
	if($db->emptyResult())
	{
		//no result found
		?>
		<h2> No result found </h2>
		<?php
	}
	else
	{
		//result found
	
		?>
			<!-- Table -->			
			<table border="1">
				<!-- Table header -->
				<tr >
					<th><a href="<?php print $_SERVER['PHP_SELF'];?>?order_by=id">Item ID</a></th>
					<th><a href="<?php print $_SERVER['PHP_SELF'];?>?order_by=itemName">Product Name</a></th>
					<th><a href="<?php print $_SERVER['PHP_SELF'];?>?order_by=description">Description</a></th>
					<th><a href="<?php print $_SERVER['PHP_SELF'];?>?order_by=supplierCode">Supplier Code</a></th>
					<th><a href="<?php print $_SERVER['PHP_SELF'];?>?order_by=cost">Cost</a></th>
					<th><a href="<?php print $_SERVER['PHP_SELF'];?>?order_by=price">Price</a></th>
					<th><a href="<?php print $_SERVER['PHP_SELF'];?>?order_by=onHand">Current Stock</a></th>
					<th><a href="<?php print $_SERVER['PHP_SELF'];?>?order_by=reorderPoint">Reorder Point</a></th>
					<th><a href="<?php print $_SERVER['PHP_SELF'];?>?order_by=backOrder">Back Order</a></th>
					<th><a href="<?php print $_SERVER['PHP_SELF'];?>?order_by=deleted">Delete/Restore</a></th>
				</tr>
				<!-- Table header end -->
				
				<!-- Table content -->	
				<?php
					while($row = mysqli_fetch_assoc($result))
					{
						?>
							<tr>
								<td><a href="add.php?id=<?php print $row['id']; ?>"><?php print $row['id']; ?></a></td>
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
							<!-- Table content end -->	
						<?php 
					}
				?>		
			<!-- Table end-->
			</table>
		<?php
	}

	//write Footer
	$header_and_footer->displayFooter();
?>