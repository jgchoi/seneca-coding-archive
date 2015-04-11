	<?php
//Include library
	include "a1.lib";
	//HTTPS control
	$https_control = new Https_control();
	$https_control->check_https();
	
	//session control
	$session_control = new Session_control();
	$session_control->session_guest();
	
	//Variables
	$err = "";
	
	//Process POST
	if($_POST){
		//variables
		$username = $_POST['username'];
		
		//check if id exit
		$db = new DBLink();
		
		$sql_query = "SELECT * FROM user WHERE username = '".$username."';";
		$result = $db->query($sql_query);
		$row = mysqli_fetch_assoc($result);
		
		//check email or login
		if(isset($_POST['password']))
		{	//check if user exist
			if($db->emptyResult())
			{
				//no result found
				$err = "Invalid login information";
			}		
			else
			{	//check password
				if(crypt($_POST['password'], $row['password']) == $row['password'])
				{
					//set session
					$_SESSION['username'] = $username;
					$_SESSION['role'] = $row['role'];
					$_SESSION['keyword'] = "";
					//set cookie
					$cookie_control = new Cookie_control();
					$cookie_control->check_keyword();
					$https_control->redirect('view.php');
					exit();
				}
				else
				{
					//invalid login information
					$err = "Invalid login information";
				}
			}
		}
		else
		{
			if($db->emptyResult())
			{
				$https_control->redirect('login.php');
				exit();
			}
			else
			{
				//account is exist, send the hint to email
				$to = "int322@localhost";
				$subject = "Your password hint.";
				$message = "Your password hint : ".$row['passwordHint'];
				$extra = "From: Webmaster <int322@localhost>\r\nReply-to: Webmaster <int322@localhost>";
				mail($to, $subject, $message, $extra);
				$https_control->redirect('login.php');
				exit();
			}
		}
	}
		
	//Header
	$header_and_footer = new HeaderAndFooter();
	$header_and_footer->displayHeader();	
	
	//Forgot Password Check
	if(isset($_GET['forgot']))
	{
	?>
		<form method="post">
			<h1>Send Password Hint</h1>
			<table border="1">
				<tr>
					<td>E-mail Address:</td>
					<td><input type="text" name="username"></td>
				</tr>
				<tr>
					<td></td>
					<td><input type="submit" value="Request"></td>
				</tr>			
				<tr>
					<td></td>
					<td style="color:red";><?php print $err;?></td>
				</tr>
			</table>
		</form>
	<?php 
	}
	else
	{
	// login print form
	?>
		<form method="post">
			<h1>Login</h1>
			<table border="1">
				<tr>
					<td>User Name:</td>
					<td><input type="text" name="username"></td>
				</tr>
				<tr>
					<td>Password:</td>
					<td><input type="password" name="password"></td>
				</tr>
				<tr>
					<td></td>
					<td><input type="submit" value="Login"></td>
				</tr>
				<tr>
					<td></td>
					<td><a href="<?php $_SERVER['PHP_SELF'];?>?forgot">Forgot your password?</a></td>
				</tr>			
				<tr>
					<td></td>
					<td style="color:red";><?php print $err;?></td>
				</tr>
			</table>
		</form>
	<?php
	}

	//write Footer
	$header_and_footer->displayFooter();
?>