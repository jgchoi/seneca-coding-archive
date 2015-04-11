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
	//Include libraries
	include('a1.lib');

	//validation variables and error messages
	$isValid = true;
	
	$errMsg1 = '';
	$errMsg2 = '';
	$errMsg3 = '';
	$errMsg4 = '';
	$errMsg5 = '';
	$errMsg6 = '';
	$errMsg7 = '';
	$errMsg8 = '';
	$errMsg9 = '';

	//run this part only if $_POST is received
	if($_POST)
	{
		$itemName	= trim($_POST['itemName']);
		$desc			= trim($_POST['desc']);
		$code			= trim($_POST['code']);
		$cost			= trim($_POST['cost']);
		$price			= trim($_POST['price']);
		$inStock		= trim($_POST['inStock']);
		$reorder		= trim($_POST['reorder']);
		$backOrder	= 'n';	
	
		//Validation
		if(empty($itemName))
		{
			$isValid = false;
			$errMsg1 = "Item name cannot be blank.";
		}
		else if(preg_match("/[^a-zA-Z0-9 :;\-,\']/", $itemName))
		{
			$isValid = false;
			$errMsg1 = "Name can only be letters, numbers and following characters ( : ; - , ' ).";
		}
		
		if(empty($desc))
		{
			$isValid = false;
			$errMsg2 = "Description cannot be blank.";
		}
		else if(preg_match("/[^a-zA-Z0-9.,\-\' \s]/m", $desc))
		{
			$isValid = false;
			$errMsg2 = "Description can only be letters, numbers and following characters ( . , ' - ).";
		}
			
		if(empty($code))
		{
			$isValid = false;
			$errMsg3 = "Code cannot be blank!";
		}
		else if(!preg_match("/^[A-Z]{3}\d{3}\d*$/",$code))
		{
			$isValid = false;
			$errMsg3 = "Item code must starts with 3 upper case letters followed by minimum 3 digits.";
		}
		
		
		if(empty($cost))
		{
			$isValid = false;
			$errMsg4 = "Cost cannot be blank!";
		}
		else if(!(preg_match('/^\d+\.\d\d$/',$cost)))
		{
			$isValid = false;
			$errMsg4 = "Format must be ###.##";
		}
		
		
		if(empty($price))
		{
			$isValid = false;
			$errMsg5 = "Price cannot be blank!";
		}
		else if(!(preg_match('/^\d+\.\d\d$/',$price)))
		{
			$isValid = false;
			$errMsg5 = "Format must be ###.##";
		}
		
		
		if(empty($inStock))
		{
			$isValid = false;
			$errMsg6 = "Stock cannot be blank!";
		}
		else if(preg_match('/\D/',$inStock))
		{
			$isValid = false;
			$errMsg6 = "Please put numeric digits only";
		}
		
		if(empty($reorder))
		{
			$isValid = false;
			$errMsg7 = "Order cannot be blank!";
		}
		else if(preg_match('/\D/',$reorder))
		{
			$isValid = false;
			$errMsg7 = "Please put numeric digits only";
		}
		
		//Set backOrder
		if(isset($_POST['backOrder']))
		{
			$backOrder = "y";
		}
		//End of validation
		
		//If validation passed
		if($isValid)
		{
			//DB command begin
			$link = dbConnection();
				
			//Making query
			$sql_query = 'INSERT INTO inventory SET ';
			$sql_query .= 'itemName="'.$itemName.'",';
			$sql_query .= 'description="'.$desc.'",';
			$sql_query .= 'supplierCode="'.$code.'",';
			$sql_query .= 'cost="'.$cost.'",';
			$sql_query .= 'price="'.$price.'",';
			$sql_query .= 'onHand="'.$inStock.'",';
			$sql_query .= 'reorderPoint="'.$reorder.'",';
			$sql_query .= 'backorder="'.$backOrder.'",';
			$sql_query .= 'deleted="n"';
			
			//Run sql query
			$result = mysqli_query($link, $sql_query) or die('query failed'. mysqli_error($link));
			
			//DB close;
			mysqli_close($link);
			
			//open view.php
			header('location:view.php');
			exit();
		}
	}// End of If POST
	
	//If POST is not exist or input is invalid
	//Header
	writeHeader();
	//Menu
	writeMenu(); 
?>
	<!--FORM START-->
		<div>
			<p >All fields mandatory except "On Back Order"</p>
			<table>
				<form name="assign1" action="add.php" method="POST">
					<tr>
						<td>Item Name : </td>
						<td><input type="text" name="itemName" value="<?php print empty($_POST['itemName']) ? '':$itemName;?>"></td>
						<td style="color:red;"><?php print $errMsg1;?></td>
					</tr>
					<tr>
						<td>Description : </td>
						<td><textarea rows="3" cols="22" name="desc"><?php print empty($_POST['desc']) ? '':$desc;?></textarea></td>
						<td style="color:red;"><?php print $errMsg2;?></td>
					</tr>
					<tr>
						<td>Supplier Code : </td>
						<td><input type="text" name="code" value="<?php print empty($_POST['code']) ? '':$code;?>"></td>
						<td style="color:red;"><?php print $errMsg3;?></td>
						</tr>
					<tr>
						<td>Cost : </td>
						<td><input type="text" name="cost" value="<?php print empty($_POST['cost']) ? '':$cost;?>"></td>
						<td style="color:red;"><?php print $errMsg4;?></td>
					</tr>
					<tr>
						<td>Selling Price : </td>
						<td><input type="text" name="price" value="<?php print empty($_POST['price']) ? '':$price;?>"></td>
						<td style="color:red;"><?php print $errMsg5;?></td>
					</tr>
					<tr>
						<td>Number on Hand : </td>
						<td><input type="text" name="inStock" value="<?php print empty($_POST['inStock']) ? '':$inStock;?>"></td>
						<td style="color:red;"><?php print $errMsg6;?></td>
					</tr>
					<tr>
						<td>Reorder Point : </td>
						<td><input type="text" name="reorder" value="<?php print empty($_POST['reorder']) ? '':$reorder;?>"></td>
						<td style="color:red;"><?php print $errMsg7;?></td>
					</tr>
					<tr>
						<td>On Back Order : </td>
						<td><input type="checkbox" name="backOrder" <?php print empty($_POST['backOrder']) ? '':'checked';?>></td>
					</tr>
					<tr>
						<td style="text-align:center" colspan="2"><input type="submit" value="Submit"></td>
					</tr>
				</form>
			</table>
		</div>
<!--FROM END-->


<?php
	//Footer
	writeFooter();
?>