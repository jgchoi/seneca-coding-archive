<?php
	//Error Status
	error_reporting(-1);
	
	//variables
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
	if($_POST){
		$itemName	= trim($_POST['itemName']);
		$desc		= trim($_POST['desc']);
		$code		= trim($_POST['code']);
		$cost		= trim($_POST['cost']);
		$price		= trim($_POST['price']);
		$inStock	= trim($_POST['inStock']);
		$reorder	= trim($_POST['reorder']);
		$backOrder	= 'N';
		$phone		= trim($_POST['phone']);
	
	
		//Validation
			//check if empty
		if(empty($itemName)){
			$isValid = false;
			$errMsg1 = "Name cannot be empty!";
		}else
			//check if not a-z A-Z
		if(!preg_match("/^[a-zA-Z]/", $itemName)){
			$isValid = false;
			$errMsg1 = "Name can only contains upper & lower alphabets.";
		}else
		if(preg_match("/[^a-zA-Z0-9 '\-]/",$itemName)){
			$isValid = false;
			$errMsg1 = "false";
		}
		
		if(empty($desc)){
			$isValid = false;
			$errMsg2 = "Description cannot be empty!";
		}else
			//Desc a-z/A-Z/0-0
		if(preg_match("/[^a-zA-Z0-9 '\s]/m", $desc)){
			$isValid = false;
			$errMsg2 = "Description can only be upper & lower alphabets and numberic digits.";
		}
			
		if(empty($code)){
			$isValid = false;
			$errMsg3 = "Code cannot be empty!";
		}else
		if(!(preg_match("/^[A-Z][0-9]{4}/",$code))){
			$isValid = false;
			$errMsg3 = "Code must be in form of A0000.";
		}
		
		
		if(empty($cost)){
			$isValid = false;
			$errMsg4 = "Cost cannot be empty!";
		}else
		if(!(preg_match('/^\d+\.\d\d$/',$cost))){
			$isValid = false;
			$errMsg4 = "Format must be ###.##";
		}
		
		
		if(empty($price)){
			$isValid = false;
			$errMsg5 = "Price cannot be empty!";
		}else
		if(!(preg_match('/^\d+\.\d\d$/',$price))){
			$isValid = false;
			$errMsg5 = "Format must be ###.##";
		}
		
		
		if(empty($inStock)){
			$isValid = false;
			$errMsg6 = "Stock cannot be empty!";
		}else
		if(preg_match('/\D/',$inStock)){
			$isValid = false;
			$errMsg6 = "Please put numeric digits only";
		}
		
		if(empty($reorder)){
			$isValid = false;
			$errMsg7 = "Order cannot be empty!";
		}else
		if(preg_match('/\D/',$reorder)){
			$isValid = false;
			$errMsg7 = "Please put numeric digits only";
		}
		
		if(empty($phone)){
			$isValid = false;
			$errMsg8 = "Phone number cannot be empty!";
		}else
		if(!preg_match('/^\d{3}-\d{3}-\d{4}$|^\(\d{3}\)[ ]\d{3}-\d{4}$|^\(\d{3}\)[ ]\d{3}[ ]\d{4}$|^\d{3}[ ]\d{3}[ ]\d{4}$/',$phone)){
			$isValid = false;
			$errMsg8 = "Please enter valid phone number";
		}
		
		if(isset($_POST['backOrder'])){
			$backOrder = 'Y';
		}
			
		if($isValid){
			//DB command begin
				include('common.php');
				
				//Making query
				$sql_query = 'INSERT INTO INVENTORY SET ';
				$sql_query .= 'itemName="'.$itemName.'",';
				$sql_query .= 'description="'.$desc.'",';
				$sql_query .= 'supplierCode="'.$code.'",';
				$sql_query .= 'cost="'.$cost.'",';
				$sql_query .= 'price="'.$price.'",';
				$sql_query .= 'onHand="'.$inStock.'",';
				$sql_query .= 'reorderPoint="'.$reorder.'",';
				$sql_query .= 'backorder="'.$backOrder.'",';
				$sql_query .= 'deleted="N"';
				
				//Run our sql query
				$result = mysqli_query($link, $sql_query) or die('query failed'. mysqli_error($link));
					header('location:view.php');
					//php exit
					exit();
				}
			
			}
		?>
<html>
	<head>
		<title>BTI320 LAb 3:add.php</title>
	</head>
	<body>
	<a href="view.php">Go to 'View.php'</a>
	<p style="font-size:0.8em;">All fields mandatory except "On Back Order"</p>
	<table>
		<form name="lab2" action="add.php" method="POST">
			<tr><td>Item Name : </td><td><input type="text" name="itemName" value="<?php echo empty($_POST['itemName']) ? '':$itemName;?>"><?php echo $errMsg1;?></td></tr>
			<tr><td><p>Description : </td><td><textarea rows="3" cols="22" name="desc"><?php echo empty($_POST['desc']) ? '':$desc;?></textarea><?php echo $errMsg2;?></td></tr>
			<tr><td>Supplier Code : </td><td><input type="text" name="code" value="<?php echo empty($_POST['code']) ? '':$code;?>"><?php echo $errMsg3;?></td></tr>
			<tr><td>Cost : </td><td><input type="text" name="cost" value="<?php echo empty($_POST['cost']) ? '':$cost;?>"><?php echo $errMsg4;?></td></tr>
			<tr><td>Selling Price : </td><td><input type="text" name="price" value="<?php echo empty($_POST['price']) ? '':$price;?>"><?php echo $errMsg5;?></td></tr>
			<tr><td>Number on Hand : </td><td><input type="text" name="inStock" value="<?php echo empty($_POST['inStock']) ? '':$inStock;?>"><?php echo $errMsg6;?></td></tr>
			<tr><td>Reorder Point : </td><td><input type="text" name="reorder" value="<?php echo empty($_POST['reorder']) ? '':$reorder;?>"><?php echo $errMsg7;?></td></tr>
			<tr><td>Phone Number : </td><td><input type="text" name="phone" value="<?php echo empty($_POST['phone']) ? '':$phone;?>"><?php echo $errMsg8;?></td></tr>
			<tr><td>On Back Order: </td><td><input type="checkbox" name="backOrder" <?php echo isset($_POST['backOrder']) ? 'checked':'';?>></td></tr>
			<tr><td style="text-align:center" rowspan="2"><input type="submit" value="Submit"></td></tr>
		</form>
	</table>

	</body>
</html>