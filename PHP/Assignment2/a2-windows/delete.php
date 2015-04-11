<?php
	/*
	Subject:				BTI320B
	Student Name:		Jung Geon Choi
	Date Submitted:	Nov. 28, 2014
	Student Declaration
	I/we declare that the attached assignment is my/our own work in accordance with Seneca Academic Policy. No part of this assignment has been copied manually or electronically from any other source (including web sites) or distributed to other students.
	Name Jung Geon Choi
	Student ID 025651134

	Assignment 2 : Add search, update, login, https, session features to assignment 1
	*/
	
	//Include common library
	include("a1.lib");

	//HTTPS control
	$https_control = new Https_control();
	$https_control->check_https();
	
	//session control
	$session_control = new Session_control();
	$session_control->session_user();

	//Receive as get delete process start
	if($_GET)
	{
		//variable creation
		$deleted = mysql_real_escape_string($_GET['deleted']);
		$id = mysql_real_escape_string($_GET['id']);

		//check if data is valid
		if( ($deleted != 'Y' && $deleted != 'N') || preg_match("/\D/",$id) )
		{
			//in case of deleted is y nor n OR id isn't number
			$https_control->redirect('view.php');
			exit();
		}
		else
		{
			//DB connection
			$db = new DBLink();

			//Query
			$sql_query  = 'UPDATE inventory ';
			$sql_query .= 'SET deleted="'.$deleted.'" ';
			$sql_query .= 'WHERE id = "'.$id.'"';
			
			//execute
			$db->query($sql_query);
			
			//redirect
			$https_control->redirect('view.php');
			exit();
		}
	}
	//Redirect if no get
	$https_control->redirect('view.php');
	exit();
?>