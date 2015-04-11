// ex_ajax.js

function ajaxFunction()
{
   /****** The XMLHttpRequest object is created   *******/
   var ajaxRequest;  /****** The variable that makes Ajax possible!   ****/
   
   /************** Browser Support Code   *************/
   try{
	/******* Modern browsers: IE 7+, Opera 8.0+, Firefox, Safari, Chrome, have a built-in XMLHttpRequest object.  **/
	ajaxRequest = new XMLHttpRequest();
	} catch (e){
		/*****  Older versions of IE: (IE5, IE6) use an ActiveX Object ***/
		try{
			ajaxRequest = new ActiveXObject("Microsoft.XMLHTTP");
		   } catch (e) {
				// Something went wrong
				alert("Your browser broke!");
				return false;
			       }
                   }
    /************** End of - Browser Support Code   *************/	
	
	/*******  Create a function that will receive data sent from the server   ***/
	ajaxRequest.onreadystatechange = function(){
	     /**** state change will call the function   ***/
		if(ajaxRequest.readyState == 4)
		{    /****  request finished and response is ready - successful. ***/
		
		    document.myForm.display1.value = ajaxRequest.responseText;
		     /*** update DOM: textbox, with the response as text ****/
		    
		    var ajaxDisplay = document.getElementById('display2');
		    /**** get DOM <div> object   ****/
		    
		    ajaxDisplay.innerHTML = ajaxRequest.responseText;
		     /*** update DOM: <div>, with the response as text ****/
		}
	}
    
        /***** Send a Request To a Server   ****/
	ajaxRequest.open("GET", "hello.txt", true);
	
	ajaxRequest.send(null);
}
