<?php
    /*
    Subject:                BTI320B
    Student Name:       Jung Geon Choi
    Date Submitted: Nov. 28, 2014
    Student Declaration
    I/we declare that the attached assignment is my/our own work in accordance with Seneca Academic Policy. No part of this assignment has been copied manually or electronically from any other source (including web sites) or distributed to other students.
    Name Jung Geon Choi
    Student ID 025651134

    Assignment 2 : Add search, update, login, https, session features to assignment 1
    */

    //Include library
    include "a1.lib";

    //HTTPS control
    $https_control = new Https_control();
    $https_control->check_https();

    //session control
    $session_control = new Session_control();
    $session_control->session_guest();

    //Variables
    $err = "";

    //Process POST
    if($_POST)
    {
        //variables
        $username = mysql_real_escape_string($_POST['username']);

        //Get user info
        $db = new DBLink();
        $sql_query = "SELECT * FROM user WHERE username = '".$username."';";
        $result = $db->query($sql_query);
        $row = mysqli_fetch_assoc($result);

        //check email or login
        if(isset($_POST['password']))
        {
            //check if user exist
            if($db->emptyResult())
            {
                //no result found
                $err = "Invalid login information";
            }
            else
            {
                //check password
                if(crypt($_POST['password'], $row['password']) == $row['password'])
                {
                    //set session
                    $_SESSION['username'] = $username; //user name
                    $_SESSION['role'] = $row['role']; //role
                    $_SESSION['keyword'] = ""; //search keyword

                    //set cookie
                    $cookie_control = new Cookie_control();
                    $cookie_control->check_keyword(); //if not set, set to id

                    //redirect to view
                    $https_control->redirect('view.php');
                    exit();
                }
                else
                {
                    //invalid login information
                    $err = "Invalid login information";
                }
            }
        }
        else
        {
            //Process email request
            if($db->emptyResult())
            {
                //Email does not exist in system
                $https_control->redirect('login.php');
                exit();
            }
            else
            {
                //account is exist, setting context
                $to = "int322@localhost";
                $subject = "Your password hint.";
                $message = "Your password hint : ".$row['passwordHint'];
                $extra = "From: Webmaster <int322@localhost>\r\nReply-to: Webmaster <int322@localhost>";

                //send mail
                mail($to, $subject, $message, $extra);

                //redirect
                $https_control->redirect('login.php');
                exit();
            }//end of email validation if
        }//end of email checking if
    }//end of post

    //Header
    $header_and_footer = new HeaderAndFooter();
    $header_and_footer->displayHeader();

    //Forgot Password Check
    if(isset($_GET['forgot']))
    {
    ?>
        <form action="<?php print $https_control->form_action("self");?>" method="post">
            <h1>Send Password Hint</h1>
            <table border="1">
                <tr>
                    <td>E-mail Address:</td>
                    <td><input type="text" name="username"></td>
                </tr>
                <tr>
                    <td></td>
                    <td><input type="submit" value="Request"></td>
                </tr>
                <tr>
                    <td></td>
                    <td style="color:red";><?php print $err;?></td>
                </tr>
            </table>
        </form>
    <?php
    }
    else
    {
    // login print form
    ?>
        <form action="<?php print $https_control->form_action("self");?>" method="post">
            <h1>Login</h1>
            <table border="1">
                <tr>
                    <td>User Name:</td>
                    <td><input type="text" name="username"></td>
                </tr>
                <tr>
                    <td>Password:</td>
                    <td><input type="password" name="password"></td>
                </tr>
                <tr>
                    <td></td>
                    <td><input type="submit" value="Login"></td>
                </tr>
                <tr>
                    <td></td>
                    <td><a href="<?php $_SERVER['PHP_SELF'];?>?forgot">Forgot your password?</a></td>
                </tr>
                <tr>
                    <td></td>
                    <td style="color:red";><?php print $err;?></td>
                </tr>
            </table>
        </form>
    <?php
    }

    //write Footer
    $header_and_footer->displayFooter();
?>