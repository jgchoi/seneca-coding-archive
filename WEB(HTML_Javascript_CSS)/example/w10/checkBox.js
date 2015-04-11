

       function checkForAtleastOne () {

       var errors              = false;
       var errorMessages       = '';

       var numberOfCheckboxes1 = document.form1.system_type.length;
       var oneChecked1         = 'no';

       for (var i = 0; i < numberOfCheckboxes1 ; i++)
       {
            if (document.form1.system_type[i].checked)
            {
                oneChecked1 = 'yes';
            }
       }


       if (oneChecked1 == 'no'){
           errorMessages += 'Please check system type.\n';
           errors = true;
       }

       if (errors) {
          alert(errorMessages);
          return false;
       }
       else {
           return true;
       }
     }  // check at least ONE


     //////////////////////////
     function checkAllOfTheAbove()
     {

        var numberOfCheckboxes1 = document.form1.system_type.length - 2;

        for (var i = 0; i < numberOfCheckboxes1 ; i++)
        {
            document.form1.system_type[i].checked = true;
        } // for
        document.form1.system_type[numberOfCheckboxes1].checked = false;
        document.form1.system_type[numberOfCheckboxes1+1].checked = false;
     } //function checkAllOfTheAbove()

     ////////////////////////////
     function checkNoneOfTheAbove()
     {

        var numberOfCheckboxes = document.form1.system_type.length - 2;

        for (var j = 0; j <= numberOfCheckboxes ; j++)
        {
            document.form1.system_type[j].checked = false;
        }
       }

     function commonSense() {

       document.form1.system_type[document.form1.system_type.length - 1].checked = false;
     }
