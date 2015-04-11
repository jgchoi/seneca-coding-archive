<?php
	//Include common library
	include("a1.lib");
	
	//HTTPS control
	$https_control = new Https_control();
	$https_control->check_https();

	//create variables
	$deleted = $_GET['deleted'];
	$id = $_GET['id'];

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

		//Command
		$sql_query = 'UPDATE inventory ';
		$sql_query .= 'SET deleted="'.$deleted.'" ';
		$sql_query .= 'WHERE id = "'.$id.'"';

		$db->query($sql_query);

		$https_control->redirect('view.php');
		exit();
	}
?>