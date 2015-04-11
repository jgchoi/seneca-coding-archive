<?php
session_start();
if(!$_SESSION['username'])
{
	header("location:login.php");
	exit();
}
?>
<h1>You are logged in ! </h1>
<a href="logout.php">Log Out</a>