function validateMyForm(form){
	if(validateName(form) == false)
		return false;
	else
	if(validateClientNumber(form) == false)
		return false;
	else
	if(validateClient(form) == false)
		return false;
	else
	if(validateDob(form) == false)
		return false;
	else
	if(validateSize(form) == false)
		return false;
	else
	if(validateSauces(form) == false)
		return false;
	else
	if(validateToppting(form) == false)
		return false;
	else
		{
			validatePassed(form);
			form.field13.value="Y";
			form.field07.disabled = false;
			return true;
		}


}

function pizzaPrice(){
	pizza.field07.disabled = false;
	
	switch (pizza.field05.value)
		{
		case "0":
			pizza.field07.value = "";
			break;
		case "1":
			pizza.field07.value = "$10.00";
			break;
		case "2":
			pizza.field07.value = "$15.00";
			break;
		case "3":
			pizza.field07.value = "$20.00";
			break;
		case "4":
			pizza.field07.value = "$25.00";
			break;
		default:
			break;		
		}
		pizza.field07.disabled = true;
	
}

function validatePassed(form){

	var newName = (form.field01.value.charAt(0).toUpperCase() + form.field01.value.substr(1,29).toLowerCase());
	form.field01.value = newName;
}

function validateName(form){
	var name = form.field01.value;
	var patt = /[^a-zA-Z'-]/;
	var testResult=patt.test(name);
	var result = false;
	
	if(name.length == 0)
		alert("Name cannot be empty");
	else
	if(testResult==true)
		alert("Name can only contains upper & lower alphabets and apostrophe(') and hyphen(-)");
	else
		result = true;
	
	if(result == false)
		{
			form.field01.focus();
			form.field01.select();
			return false;
		}
	else
		{
			return true;
		}
}

function validatePhoneNumber(form){
	var phoneNumber = form.field03.value;
	var result = false;
	var patt = /[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]/;
	
	
	if(phoneNumber.length != 12)
		alert("Phone number must be 12 digits");
	else
	if(patt.test(phoneNumber) == false)
		alert("Phone number must be in form of ###-###-####");
	else
	if(phoneNumber.substr(0,3) == "000")
		alert("Area code cannot be 000");
	else
	if(phoneNumber.substr(4,8) == "000-0000")
		alert("Phone nubmer cannot be 000-0000");
	else
	if(phoneNumber.substr(0,3) == "416" && form.field02.value.charAt(0) == "T")
		result = true
	else
	if(phoneNumber.substr(0,3) == "905" && form.field02.value.charAt(0) == "G")
		result = true;
	else
		alert("Area code is not matched. 'T' client must have 416 and 'G' client must have 905");
	
		
	if(result == false)
		{
			form.field03.focus();
			form.field03.select();
			return false;
		}
	else
		{
			return true;
		}
}

function validateClient(form){
	var result = false;
	if(validateClientNumber(form) == false)
		return false;
	else
	if(validatePhoneNumber(form) == false)
		return false;
	else
		return true;
}

function validateClientNumber(form){
	var clientNum = form.field02.value;
	var result = false;
	
	if(clientNum.length != 12)
		alert("Client number must be 12 digits");
	else
	if(clientNum.charAt(0) != 'T' && clientNum.charAt(0) != 'G')
		alert("Client number must be started with either 'T' or 'G'");
	else
	if(clientNum.charAt(6) != '-')
		alert("Missing hyphen(-). Please insert in form of A12345-12345");
	else
	if(parseInt(clientNum.substr(1,5)) != clientNum.substr(1,5))
		alert("Non-numaric input found before hyphen. Please enter in form of A12345-12345");
	else
	if(parseInt(clientNum.substr(7.5)) != clientNum.substr(7,5))
		alert("Non-numaric input found after hyphen. Please enter in form of A12345-12345");
	else
		result = true;
		
		
	if(result == false)
		{
			form.field02.focus();
			form.field02.select();
			return false;
		}
	else
		{
			return true;
		}
}

function validateDob(form){
	var bday = form.field04.value;
	var patt = /jan|feb|mar|apr|may|jun|jul|aug|sep|oct|nov|dec/i
	var result = false;
	


	
	if(bday.length != 7)
		alert("D.O.B must be 7 digits")
	else
	if(parseInt(bday.substr(3,4)) != bday.substr(3,4))
		alert("Birth day's year should be 4 numeric digits only");
	else
	if(parseInt(bday.substr(3,4)) > 1995)
		alert("Customer must be older than 19 years old");
	else
	if(patt.test(bday.substr(0,3))==false)
		alert("Birth day's month in form of 3 letters represent month.\n E.g JAN1989");
	else
		result = true;
		
	if(result == false)
		{
			form.field04.focus();
			form.field04.select();
			return false;
		}
	else
		{
			return true;
		}
}

function validateSize(form){
	var size = form.field05.value;
		
	if(size == 0)
		{
			alert("Please select size");
			form.field05.focus();
			return false;
		}
	else
		{
			return true;
		}
	
}

function validateSauces(form){
	var result = false;
	
	
	for(var i=0;i<4;i++)
		{
			if(form.field09[i].checked == true)
				result = true;
		}
		
	if(result == false)	
		{
			alert("Please select sauce")
			form.field09.focus;
			return false;
		}
	else
		{
			return true;
		}
		
}

function validateToppting(form){
	var result = false;
	
	for(var i=0;i<8;i++)
		{
			if(form.field10[i].checked == true)
				result = true;
		}
		
	if(result == false)	
		{
			alert("Please select at least one topping")
			form.field10.focus;
			return false;
		}
	else
		{
			return true;
		}
}
