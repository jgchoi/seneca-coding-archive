<html>
<head>
	<title>BTI320 LAb 3:add.php</title>
</head>
<body>
	<?php
		
				

				print_r($_POST);
				exit();
			
		
		
	?>
	<p style="font-size:0.8em;">All fields mandatory except "On Back Order"</p>
	<table>
		<form name="lab2" action="add22.php" method="POST">
			<tr><td>Item Name : </td><td><input type="text" name="itemName" value="<?php echo empty($_POST['itemName']) ? '':$itemName;?>"><?php echo $errMsg1;?></td></tr>
			<tr><td><p>Description : </td><td><textarea rows="3" cols="22" name="desc"><?php echo empty($_POST['desc']) ? '':$desc;?></textarea><?php echo $errMsg2;?></td></tr>
			<tr><td>Supplier Code : </td><td><input type="text" name="code" value="<?php echo empty($_POST['code']) ? '':$code;?>"><?php echo $errMsg3;?></td></tr>
			<tr><td>Cost : </td><td><input type="text" name="cost" value="<?php echo empty($_POST['cost']) ? '':$cost;?>"><?php echo $errMsg4;?></td></tr>
			<tr><td>Selling Price : </td><td><input type="text" name="price" value="<?php echo empty($_POST['price']) ? '':$price;?>"><?php echo $errMsg5;?></td></tr>
			<tr><td>Number on Hand : </td><td><input type="text" name="inStock" value="<?php echo empty($_POST['inStock']) ? '':$inStock;?>"><?php echo $errMsg6;?></td></tr>
			<tr><td>Reorder Point : </td><td><input type="text" name="reorder" value="<?php echo empty($_POST['reorder']) ? '':$reorder;?>"><?php echo $errMsg7;?></td></tr>
			<tr><td>Phone Number : </td><td><input type="text" name="phone" value="<?php echo empty($_POST['phone']) ? '':$phone;?>"><?php echo $errMsg8;?></td></tr>
			<tr><td>On Back Order: </td><td><input type="checkbox" name="backOrder" <?php echo isset($_POST['backOrder']) ? 'checked':'';?>></td></tr>
			<tr><td>Color</td><td>
				<select name='color'>
					<option name='color_none' <?php echo isset($_POST['color'])&&($_POST['color'])=='--Choose one--'?'selected':'';?>>--Choose one--</option>
					<option name='color_red' <?php echo isset($_POST['color'])&&($_POST['color'])=='Red'?'selected':'';?>>Red</option>
					<option name='color_blue' <?php echo isset($_POST['color'])&&($_POST['color'])=='Blue'?'selected':'';?>>Blue</option>
				</select>
				<?php echo $errMsg9;?>
			</td></tr>
			<tr><td>Status</td><td>
				<input type="radio" name="status" value="active" <?php echo isset($_POST['status'])&&($_POST['status'])=='active'?'checked':'';?>>Active
				<input type="radio" name="status" value="Inactive" <?php echo isset($_POST['status'])&&($_POST['status'])=='Inactive'?'checked':'';?>>Inactive
				<?php echo $errMsg10;?>
			</td></tr>
			<tr><td style="text-align:center" rowspan="2"><input type="submit"></td></tr>
		</form>
	</table>

</body>
</html>