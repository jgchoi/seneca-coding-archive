<?php
	if($_POST)
	{
		setcookie($_POST['name'],$_POST["value"], time()+3600);
	}
	
	if($_COOKIE){
		//Incerease the visit count
		if($_COOKIE['numVisited'])
		setcookie('numVisited',$_COOKIE['numVisited']+1, time()+3600);
		else
		setcookie('numVisited',1, time()+3600);
	
		?>

		
		<pre>
		<?php print_r($_COOKIE);?>
		</pre>
		<br>
		<h1>Welcome back ! - You visitied this page 	<?php print $_COOKIE['numVisited'];	?> times.</h1>
		<?php
		}
?>

<form method="POST">
	Name of Cookie :<input type="text" name="name">
	<br>
	Value of Cookie :<input type="text" name="value">
	<br>
	<input type="submit">
</form>