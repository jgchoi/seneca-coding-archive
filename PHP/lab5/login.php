<?php
	session_start();
	$err = "";
	if($_POST){
		include "common.php";
		$link = connectDB();
		if(isset($_POST['email'])){
			//email request
			$query = "SELECT * FROM user WHERE username like \"".$_POST['username']."\";";
			$result = mysqli_query($link, $query) or die('query failed'. mysqli_error($link));

			if(mysqli_num_rows($result) != 1){
				header("location:login.php");
				exit();
			}else{
				//send email
				header("location:login.php");
				$row = mysqli_fetch_assoc($result);
				$to = $row['username'];
				$subject = "Your password hint is here.";
				$message = "Your password hint is following:<br>".$row['passwordHint'];
				$extra = "From: Webmaster <int322@localhost>\r\nReply-to: Webmaster <int322@localhost>";
				mail( $to, $subject, $message, $extra);
				exit();
			}
		}else{
			//regular login
			$query = "SELECT * FROM user WHERE username like \"".$_POST['username']."\";";
			$result = mysqli_query($link, $query) or die('query failed'. mysqli_error($link));
			$row = mysqli_fetch_assoc($result);
			if( crypt($_POST['password'],$row['password']) == $row['password']){
			$_SESSION['username'] = $_POST['username'];
			header("location:protectedstuff.php");
			exit();
				}
				else{ $err = "Invalid login information.";}
			}
		}	
?>
<form method="POST">
User name<input type="text" name="username"><br>
Password <input type="password" name="password"><br>
<input type="submit"><br>
<?php print $err;?>
<a href="login.php?forgot=1">Forgot your password?</a>
<?php
if($_GET){
	if($_GET['forgot'] == 1){
		?>
		<br>E-Mail Address:<input type="text" name="email">
		<input type="submit"><br>
		<?php
	}
}?>
</form>