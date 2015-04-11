<?php
class DBLink {
	private $link;
	private $num_result;
	public function __construct(){
		// $lines = file('/home/int322/secret/topsecret');
		// $dbserver = trim($lines[0]);
		// $uid = trim($lines[1]);
		// $pw = trim($lines[2]);
		// $dbname = trim($lines[3]);
		
		$dbserver = "localhost";
		$uid = "root";
		$pw = "ab890103";
		$dbname = "int322";
		
		$this->link = mysqli_connect($dbserver, $uid, $pw, $dbname)
		or die('Could not connect: ' . mysqli_error($this->link));
	}
	public function query($sql_query){
		$result = mysqli_query( $this->link, $sql_query) or die('Query error: ' . mysqli_error($this->link));
		$this->num_result = mysqli_num_rows($result);
		return $result;
	}
	public function __destruct(){
		mysqli_close( $this -> link );
	}
	public function emptyResult(){
		return $this->num_result == 0 ? true : false;
	}
}
class Menu{
	private $menu;
	public function __construct($string){
		$this->menu = $string;
	}
	public function display(){
		foreach($this->menu as $i)
			print $i ;
	}
}	
?>