<?php
include("common.php");

$sql_query = 'UPDATE INVENTORY ';
$sql_query .= 'SET deleted="'.$_GET['deleted'].'" ';
$sql_query .= 'WHERE id = "'.$_GET['id'].'"';
mysqli_query($link, $sql_query) or die('query failed'. mysqli_error($link));
header("location:view.php");
?>