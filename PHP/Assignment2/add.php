<?php
	//Include libraries
	include('a1.lib');
	
	//HTTPS control
	$https_control = new Https_control();
	$https_control->check_https();	

	
	//session control
	$session_control = new Session_control();
	$session_control->session_user();

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
	
	$itemName	= '';
	$desc			= '';
	$code		= '';
	$cost			= '';
	$price			= '';
	$inStock		= '';
	$reorder		= ''; 
	$backOrder	= '';
	
	//Check get
	if($_GET)
	{
		$id = $_GET['id'];
		
		//validate id
		$db = new DBLink();
		$sql_query = "Select * from inventory where id = ".$id.";";
		$result = $db->query($sql_query);
		if($db->emptyResult())
		{
			//wrong id
			unset($id);
		}
		else
		{
		$row = mysqli_fetch_assoc($result);
		$itemName	= ($row['itemName']);
		$desc			= ($row['description']);
		$code		= ($row['supplierCode']);
		$cost			= ($row['cost']);
		$price			= ($row['price']);
		$inStock		= ($row['onHand']);
		$reorder		= ($row['reorderPoint']);
		$backOrder	= ($row['backOrder']);
		}
	}

	//run this part only if $_POST is received
	if($_POST)
	{
		if(isset($_POST['id']))
		$id				= $_POST['id'];
		$itemName	= trim($_POST['itemName']);
		$desc			= trim($_POST['desc']);
		$code		= trim($_POST['code']);
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
			$db = new DBLink();
		
			//check if it is update or insert
			if(isset($id))
			{
				//$id is set, making update query
				$sql_query = "UPDATE inventory SET ";
				$sql_query .= 'itemName="'.$itemName.'",';
				$sql_query .= 'description="'.$desc.'",';
				$sql_query .= 'supplierCode="'.$code.'",';
				$sql_query .= 'cost="'.$cost.'",';
				$sql_query .= 'price="'.$price.'",';
				$sql_query .= 'onHand="'.$inStock.'",';
				$sql_query .= 'reorderPoint="'.$reorder.'",';
				$sql_query .= 'backorder="'.$backOrder.'" ';
				$sql_query .= 'WHERE id = '.$id.';';
				
			
				//Run sql query
				$result = $db->query($sql_query);
				
				//open view.php
				$https_control->redirect('view.php');
				exit();
			}
			else
			{	
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
				$result = $db->query($sql_query);
				
				//open view.php
				$https_control->redirect('view.php');
				exit();
			}
		}
	}// End of If POST
	
	//Header
	$header_and_footer = new HeaderAndFooter();
	$header_and_footer->displayHeader();	
	
	//menu
	$menu = new Menu();
	$menu->display($_SESSION['keyword'], $_SESSION['username'],$_SESSION['role']);
?>
	<!--FORM START-->
		<div>
			<p >All fields mandatory except "On Back Order"</p>
			<table border="1">
				<form name="assign1" action="add.php" method="POST">
					<?php if(isset($id)) {?>
					<tr>
						<td>Item Id</td>
						<td><input type="text" name="id" value="<?php print $id;?>" readonly="readonly"></td>
						<td></td>
					</tr>
					<?php }?>
					<tr>
						<td>Item Name : </td>
						<td><input type="text" name="itemName" value="<?php print $itemName;?>"></td>
						<td style="color:red;"><?php print $errMsg1;?></td>
					</tr>
					<tr>
						<td>Description : </td>
						<td><textarea rows="3" cols="22" name="desc"><?php print $desc;?></textarea></td>
						<td style="color:red;"><?php print $errMsg2;?></td>
					</tr>
					<tr>
						<td>Supplier Code : </td>
						<td><input type="text" name="code" value="<?php print $code;?>"></td>
						<td style="color:red;"><?php print $errMsg3;?></td>
						</tr>
					<tr>
						<td>Cost : </td>
						<td><input type="text" name="cost" value="<?php print $cost;?>"></td>
						<td style="color:red;"><?php print $errMsg4;?></td>
					</tr>
					<tr>
						<td>Selling Price : </td>
						<td><input type="text" name="price" value="<?php print $price;?>"></td>
						<td style="color:red;"><?php print $errMsg5;?></td>
					</tr>
					<tr>
						<td>Number on Hand : </td>
						<td><input type="text" name="inStock" value="<?php print $inStock;?>"></td>
						<td style="color:red;"><?php print $errMsg6;?></td>
					</tr>
					<tr>
						<td>Reorder Point : </td>
						<td><input type="text" name="reorder" value="<?php print $reorder;?>"></td>
						<td style="color:red;"><?php print $errMsg7;?></td>
					</tr>
					<tr>
						<td>On Back Order : </td>
						<td><input type="checkbox" name="backOrder" <?php print $backOrder=='y' ? 'checked':'';?>></td>
					</tr>
					<tr>
						<td style="text-align:center" colspan="2"><input type="submit" value="<?php print isset($id) ? "Modify" : "Submit";?>"></td>
					</tr>
				</form>
			</table>
		</div>
	<!--FORM END-->


<?php
	//write Footer
	$header_and_footer->displayFooter();
?>