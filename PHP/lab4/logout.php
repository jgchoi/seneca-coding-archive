<?php
	session_start();
	session_destroy();
	setcookie("PHPSESSID", "", time() - 61200,"/");
	header('location:login.php');
	?>