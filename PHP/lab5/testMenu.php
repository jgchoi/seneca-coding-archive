<?php 
include "myClasses.php";
$string = array(	"<a href='testMenu.php'>testMenu.php::</a>",
						"<a href='testDB.php'>testDB.php::</a>",
						"<a href='protected2.php'>protected2.php::</a>",
						"<a href='logout.php'>logout.php::</a>",
						"<a href='protectedstuff.php'>protectedstuff.php::</a>");
$menu = new Menu($string);
$menu->display();
?>