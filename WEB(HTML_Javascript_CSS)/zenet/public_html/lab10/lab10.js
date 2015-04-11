function enough(){
	var x = document.getElementById("id_content");
	x.innerHTML="<button style='width=100px;height=100px;' ondblclick='show_content();'>Let me show you What I have(double click!)</button>";
}

function changeBg(xxx){
	var x = document.body;
	var y = ["black","yellow","green","brown","blue","red","gold","pink","grey","purple"];
	var z = Math.floor(Math.random() * 10);
	x.style.backgroundColor = y[z];

}

function show_title(){
	var x = document.getElementById("id_title");
	x.innerHTML="<h1>Lab 9 & 10 : Practice with DOM Elements and Canvas</h1><span id='byebye'><button onclick='align_text();'>Make is center!</button></span><hr/>";
	
}
function align_text(){
	var x = document.getElementById("id_title");
	x.style.textAlign="center";
	x = document.getElementById("byebye");
	x.innerHTML="";
}
function show_content(){
	var x = prompt("Hey! What's your name?");
	document.getElementById("id_content").innerHTML="<p>Hey! " + x + ", nice to see you ! <br/>Let me ask few more questions about you !"+
			"<p>Your Credit Card Number : <input onblur='joke(this);' type='text' size='16' maxlength='16'></p>"+
					"<canvas onmousemove='draw();' id='my_can' width='500' height='300' style='border:1px solid gold;'></canvas>"+
					
					"<p> <button onclick='bye();'>ByeBye!</button></form>"
	}
function draw(){
	var z = document.getElementById("my_can");
	var ctx = z.getContext("2d");
	var x1 = Math.floor(Math.random() * 500);
	var y1 = Math.floor(Math.random() * 500);
	var x2 = Math.floor(Math.random() * 500);
	var y2 = Math.floor(Math.random() * 500);
	

	ctx.moveTo(x1,y1);
	ctx.lineTo(x2,y2);
	ctx.stroke();
	
}
function joke(x){
	x.value="just kidding!";
	x.disabled='true';
}
function bye(){
 
	winwin=window.open("http://google.ca","win_bye","width=500,height=300.scrollbars=no");
	winwin.document.write("<h1 style='text-align:center;'>Thank you for giving me <br/>another A+ Sunny! <br/>Hope to see you in</br> next semester as well!<br></h1>");
}