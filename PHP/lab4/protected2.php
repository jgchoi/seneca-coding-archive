<?php
session_start();
if(!$_SESSION['username'])
{
	header("location:login.php");
	exit();
}
print_r($_SESSION);
?>
<a href="logout.php">Log Out</a>
