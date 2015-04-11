function check(f){
	var result = false;

	if(f.field01.value.length == 0)
		{alert("Please type something");f.field01.focus();}
	else if(f.field01.value.match(/[^a-zA-Z]/))
		{alert("Alphabet only");f.field01.focus();}
	else if(f.field02.value.match(/[0-9]/))
		{alert("No number on comment");f.field02.focus();}
	else if(f.field03[0].checked == false)
		alert("Pleas choose 1")
	else if(f.field03[1].checked == true)
		alert("Please do not choose 2")
	else if(f.field04[0].checked == false && f.field04[1].checked == false)
		alert("Please choose one of 3 or 4")
	else if(f.field05.value == 1)
		alert("sorry I am busy at 9-10. See you in different time")		
	else if(f.field06[1].selected==false ||f.field06[2].selected==false)
		alert("Hint. Best course usually listed on top");
	else
		result = true;
	
	
	if(result == false)
		return false;
	else
		return true;
}

