
function formValidation()
{
 // if (validateName() && validateClientNum() && validatePhone())
 //  if (validateClientNum())
   if (validateName() && validateClientNum() &&  validatePhone()&& validateDOB() && validateSize())
   
 //if (validateName() && validateClientNum() )
       { 
          var surname = document.pizza.field01.value;
          document.pizza.field01.value = (surname.substr(0,1)).toUpperCase() + (surname.substr(1).toLowerCase());
          document.pizza.field13.value = "Y";
          
          // calculate price
         var size = document.pizza.field05.selectedIndex;
         var priceArray = new Array(0, 11.55, 15.25, 22, 25);
         var price = priceArray[size] * 1.13;
          document.pizza.field07.value = price.toFixed(2);
            return true;
        }
      else
        {
            return false;
        }

} // formValidation

function isAlpha(x)
{
  var alphString = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  if (alphString.indexOf(x)>=0)
     return true;
  else
     return false;
}

function isNum(x)
{
  var numString = "0123456789";
  if (numString.indexOf(x)>=0)
     return true;
  else
     return false;
}
function validateName()
{  
  var alphString = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  var eachChar;
  var count_alpha=0, count_invalid = 0;
  
  var inputValue = document.pizza.field01.value;
  if (inputValue.length < 1)
   {      /* check the length     */
     alert("Surname: Please enter a meaningful name (at least 1 alphabetic character).\n");
     return false;
   }
   else // user input at least 1 char
   {
      for (var i = 0; i < inputValue.length; i++)
      {
        eachChar= inputValue.substr(i,1);
      // check at least one character is a letter
      if (alphString.indexOf(eachChar)>= 0)
      {
         count_alpha++;
       }
      else // not alpha, check - '
      {
        if (!(eachChar=="'" || eachChar == "-"))
        {
           count_invalid++;
        }
      }
       }  // for
 
    } // else
    
   if (count_alpha<1 || count_invalid >0)
       {
           alert("Surname: Allow: alpha, -, ', input at least one alpha.\n");
           document.pizza.field01.focus();
           return false; 
     }
   else 
      return true;
}//validateName()

function validateClientNum()
{
  var input = document.pizza.field02.value;
  var len = input.length;
 if (len !=12)
  {
    alert("ClientNum: need 12 positions");
    document.pizza.field02.focus();
    return false;
  }
  else // input 12 characters
  {
    if (input.substr(0,1)!='T' && input.substr(0,1)!= 'G')
    {
      alert("ClientNum: first char should be Alpha 'T' or 'G'");
      document.pizza.field02.focus();
      return false;
    }
     if (input.substr(6,1) !="-")
    {
      alert("ClientNum: position 7 should be -");
      document.pizza.field02.focus();
      return false;
    }
    for (var i=1; i<=5; i++)
    {
      if (!isNum(input.substr(i,1)))
      {
        alert("ClientNum: position 2-6 should be numbers");
        document.pizza.field02.focus();
        return false;
      }
    } // position 2-6
    
    for (var i=7; i<=11; i++)
    {
      if (!isNum(input.substr(i,1)))
      {
        alert("ClientNum: position 2-6 should be numbers");
        document.pizza.field02.focus();
        return false;
      }
    } // position 8-12 
  }//else, check 12 chars 
  return true;
}//function validateClientNum()

function validatePhone()
{
  var input = document.pizza.field03.value;
  var len = input.length;
  if (len !=12)
  {
    alert("PhoneNum: need 12 positions");
    document.pizza.field03.focus();
    return false;
  }
  else // input 12 characters
  {
    if (document.pizza.field02.value.substr(0,1) == 'T' && input.substr(0,3) != "416")
     {
      alert("ClientNum starts with 'T', phone should be '416'");
      document.pizza.field03.focus();
      return false;
    }
        
     if (document.pizza.field02.value.substr(0,1) == 'G' && input.substr(0,3) != "905")
     {
      alert("ClientNum starts with 'G', phone should be '905'");
      document.pizza.field03.focus();
      return false;
    }
    if ((input.substr(3,1) !="-")||(input.substr(7,1) !="-"))
    {
      alert("phone should be: nnn-nnn-nnn ");
      document.pizza.field03.focus();
      return false;
    }  
  }// else have 12 chars
   return true;
 } // validatephone()

function validateDOB()
{ 
  var input = document.pizza.field04.value;
  var len = input.length;
  if (len != 7)
  {
    alert("DOB: need 7 positions");
    document.pizza.field04.focus();
    return false;
  }
  else // input 7 characters
  {
    if (!isMonth(input.substr(0, 3)))
    {
      alert("DOB month invalid");
      document.pizza.field04.focus();
      return false;
    }
    if (2011 - eval(input.substr(3,4))  < 19)
    {
       alert("at least 19 yrs old");
      document.pizza.field04.focus();
      return false;
    }
  }// else 7 chars
  return true;
  
}//validateDOB()

function isMonth(x)
{
  var mon= new Array("jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec");
  for (var i = 0; i<12; i++)
    if (x.toLowerCase() == mon[i])
      return true;
  return false;
}

function validateSize()
{
   if (document.pizza.field05.selectedIndex < 1) // first is select size
      {
          alert("select one pizza size!");
          document.pizza.field05.focus();
          return false;
          
       }
   /*
   else // selected size, recalculate price
   {
     var size = document.pizza.field05.selectedIndex;
     var priceArray = new Array(0, 11.55, 15.25, 22, 25);
     var price = priceArray[size] * 1.13;
     document.pizza.field07.value = price.toFixed(2);
   }// recalculate price
   */
    return true;
  
} //validateSize()