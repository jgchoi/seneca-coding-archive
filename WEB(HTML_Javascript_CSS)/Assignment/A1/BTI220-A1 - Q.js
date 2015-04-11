/*
I declare that this is wholly my own work in accordance with Seneca 
Academic Policy.  No part of this work has been copied manually or 
electronically from any other source (including web sites) or 
distributed to other students. 
 
Name   _____Jung Geon Choi________   Student ID ____025651134____ 
*/

/*
Name : Jung Geon Choi
Code : BTI220
Section : B
Due : Feb. 16, 2014
*/

var student = new Array(30);
var teacher = new Array(4);
var i = 0; var j = 0;
var stuNum = 0;
var tmp;

	  
var subjectStudent = {
	name:"",
	id:"",
	courses:["BTP200","BTD210","BTI220","BTC240"],
	marks:[4],
	avg:0
};

var subjectTeacher = {
	name:"",
	course:"",
	office:"",
	email:"",
	avg:0
};

//student input
while(i<30)
	{
	student[i] = Object.create(subjectStudent);
	
	//name
	student[i].name = prompt("Enter student's name");
	
	if(student[i].name == "!!!")
		{
		break;
		}
	else
		{	
		//id
		student[i].id = prompt("Enter student's id");
		
		//marks
		for(j=0;j<4;j++)
			{
			student[i].marks[j] = getMark(student[i].courses[j]);
			
			//DEBUG
			alert("student[0].marks = " + student[0].marks);
			if(i>0)
			 alert("Student[0].makrs = " + student[0].marks + " Student[i].marks = " + student[i].marks);
			
			//sum marks for avg
			student[i].avg = student[i].avg + student[i].marks[j];
			}
		//debug		
		
		
		//find avg by /4
		student[i].avg = student[i].avg/4;
		
		//keep max number to index 0
		if(i>0)
			{
			if(student[i].avg > student[0].avg)
				{
				tmp = student[i];
				student[i] = student[0];
				student[0] = tmp;
				}
			}
		
		i++;
		stuNum++;
		}
	}
alert(student[0].marks+"\n"+student[1].marks);


//teacher input
i = 0;
while(i<4)
	{
	teacher[i] = Object.create(subjectTeacher);
	
	//name
	teacher[i].name = prompt("Enter teacher's name");
	
	//course
	teacher[i].course = prompt("Enter teaching course");
	
	//office
	teacher[i].office = prompt("Enter office");
	
	//email
	teacher[i].email = getEmail();
	
	//find code
	for(j=0;j<4;j++)
		{
		if(teacher[i].course == student[0].courses[j])
			{
			var code = j;
			}
		}
	
	
	//sum
	for(j=0;j<stuNum;j++)
		{
		teacher[i].avg = teacher[i].avg + student[j].marks[code]
		}
		
	//avg
		teacher[i].avg = teacher[i].avg/stuNum;
		
	//keep max number to index 0
		if(i>0)
			{
			if(teacher[i].avg > teacher[0].avg)
				{
				tmp = teacher[i];
				teacher[i] = teacher[0];
				teacher[0] = tmp;
				}
			
		     }
	i++;
	}	    
	
//output student
alert("The student with the highest overall average is :\n" +
	  "Student Name: " + student[0].name + "\n" +
	  "Student ID: " + student[0].id + "\n" +
	  "Courses: " + student[0].courses + "\n" +
	  "Marks: " + student[0].marks + "\n" +
	  "Average mark: " + student[0].avg + "\n");

//output teacher
alert("The course with the highest average mark is " + teacher[0].course + ". It is taught by:" +
	  "Prof Name: " + teacher[0].name + "\n" +
	  "Course: " + teacher[0].course + "\n" +
	  "Office: " + teacher[0].office + "\n" +
	  "Email: " + teacher[0].email + "\n" +
	  "Average mark: " + teacher[0].avg + "\n");


function getMark(course)
{
var mark = -1;
	while(mark == -1)
		{
		var mark = prompt("Input mark for " + course);
		mark = parseFloat(mark);
		
		
		//validation
		if(isNaN(mark)==true)
			{
			alert("Number ONLY");
			mark = -1;
			}
		else if(mark <0 || mark >100)
			{
			alert("Range is 0-100");
			mark = -1;
			}
		else
			{
			;
			}
		}
	return mark;
}

function getEmail()
{
	var email = 0;
	while(email == 0)
		{
		var email = prompt("Enter E-mail");
		
		if(email.match(/@senecacollege.ca/)!="@senecacollege.ca")
			{
			alert("Domain must be @senecacollege.ca");
			email = 0;
			}
		}
}