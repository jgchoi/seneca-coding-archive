<html>
<head>
	<title>BTI320 LAb 2:add.php</title>
</head>
<body>
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
	
		//run this part only if $_POST is received
		if($_POST){
			//validation
				if (empty($_POST['itemName'])){$isValid = false;$errMsg1 = "Name cannot be empty!";}
				if (empty($_POST['desc'])){$isValid = false;$errMsg2 = "Description cannot be empty!";}
				if (empty($_POST['code'])){$isValid = false;$errMsg3 = "Code cannot be empty!";}
				if (empty($_POST['cost'])){$isValid = false;$errMsg4 = "Cost cannot be empty!";}
				if (empty($_POST['price'])){$isValid = false;$errMsg5 = "Price cannot be empty!";}
				if (empty($_POST['inStock'])){$isValid = false;$errMsg6 = "Stock cannot be empty!";}
				if (empty($_POST['reorder'])){$isValid = false;$errMsg7 = "Order cannot be empty!";}

				
				
				if($isValid)
					{include "displayforminfo.php";exit();}
					
		}
	?>
	<p style="font-size:0.8em;">All fields mandatory except "On Back Order"</p>
	<table>
		<form name="lab2" action="add.php" method="POST">
			<tr><td>Item Name : </td><td><input type="text" name="itemName" value="<?php echo empty($_POST['itemName']) ? '':$_POST['itemName'];?>"><?php echo $errMsg1;?></td></tr>
			<tr><td><p>Description : </td><td><textarea rows="3" cols="22" name="desc"><?php echo empty($_POST['desc']) ? '':$_POST['desc'];?></textarea><?php echo $errMsg2;?></td></tr>
			<tr><td>Supplier Code : </td><td><input type="text" name="code" value="<?php echo empty($_POST['code']) ? '':$_POST['code'];?>"><?php echo $errMsg3;?></td></tr>
			<tr><td>Cost : </td><td><input type="text" name="cost" value="<?php echo empty($_POST['cost']) ? '':$_POST['cost'];?>"><?php echo $errMsg4;?></td></tr>
			<tr><td>Selling Price : </td><td><input type="text" name="price" value="<?php echo empty($_POST['price']) ? '':$_POST['price'];?>"><?php echo $errMsg5;?></td></tr>
			<tr><td>Number on Hand : </td><td><input type="text" name="inStock" value="<?php echo empty($_POST['inStock']) ? '':$_POST['inStock'];?>"><?php echo $errMsg6;?></td></tr>
			<tr><td>Reorder Point : </td><td><input type="text" name="reorder" value="<?php echo empty($_POST['reorder']) ? '':$_POST['reorder'];?>"><?php echo $errMsg7;?></td></tr>
			<tr><td>On Back Order: </td><td><input type="checkbox" name="backOrder" <?php echo isset($_POST['backOrder']) ? 'checked':'';?>></td></tr>
			<tr><td style="text-align:center" rowspan="2"><input type="submit"></td></tr>
		</form>
	</table>

</body>
</html>