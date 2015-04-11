<?php

function connectDB(){
//DB command begin
	//DB variables
// $lines = file('/home/int322/secret/topsecret');
		// $dbserver = trim($lines[0]);
		// $uid = trim($lines[1]);
		// $pw = trim($lines[2]);
		// $dbname = trim($lines[3]);
		
		$dbserver = "localhost";
		$uid = "root";
		$pw = "ab890103";
		$dbname = "int322";

	//DB connection
	$link = mysqli_connect($dbserver, $uid, $pw, $dbname)
			or die('Could not connect: ' . mysqli_error($link));

	return $link;
					}	
?>