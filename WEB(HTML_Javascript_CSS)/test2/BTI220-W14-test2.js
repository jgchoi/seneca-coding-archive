function validAll()
{
    if (validName() && validSubject())  //&& validProgram() 
       return true;
    return false;
}

function validName()
{
   var name = document.test2.name.value;
   
   var i, counter = 0;
   var eachC;
   if (name.length<1)
   {
      alert("Name is requred! Please enter your name.");
      document.test2.name.focus();
      document.test2.name.select();
      return false;
   }
   else
   {

      for (i=0; i<name.length; i++)
      {
         eachC = name.substr(i,1);
         if (eachC >='A' && eachC <='Z' || eachC >='a' && eachC <='z' )
             counter++;
      }
      if (counter==0)
      {
         alert("Please at least one alphabet in your name.");
         document.test2.name.focus();
         document.test2.name.select();
         return false; 
      }
      else return true;
   }
   
}


function validSubject()
{
   var counter=0;
   var i;
   var num = document.test2.subject.length;
   for (i=0; i<num; i++)
   {
      if (document.test2.subject[i].checked)
      {
         counter++;
      }
   }
   
   if (counter ==0)
   {  
     alert("Please select at least one subject.");
     return false;
    }
    else return true;
}

/*
function validProgram()
{
   var sel = document.test2.program.selectedID;
   if (sel == -1)
   {
     alert("Please select your program.");
     return false;
   }
   else return true;
}

*/