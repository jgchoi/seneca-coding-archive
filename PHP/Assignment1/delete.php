<?php
	/*
	 * Course : BTI320B
	 * Name : Jung Geon Choi
	 * Date Submitted : Oct. 14, 2014
	 *
	 * Student Declaration
	 * I/we declare that the attached assignment is my/our own work in accordance with Seneca Academic Policy. No part of this assignment has been copied manually or electronically from any other source (including web sites) or distributed to other students.
	 * Name Jung Geon Choi
	 * Student ID 025651134
	 *
	*/

	//library
	include("a1.lib");

	//DB connection
	$link = dbConnection();

	//Command
	$sql_query = 'UPDATE inventory ';
	$sql_query .= 'SET deleted="'.$_GET['deleted'].'" ';
	$sql_query .= 'WHERE id = "'.$_GET['id'].'"';

	mysqli_query($link, $sql_query) or die('query failed'. mysqli_error($link));

	//DB close;
	mysqli_close($link);

	//Redirect to view.php
	header("location:view.php");
	exit();
?>