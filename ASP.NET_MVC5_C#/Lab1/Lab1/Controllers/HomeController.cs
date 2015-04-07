using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lab1.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "This app enables me to learn something about ASP.NET MVC";

            var me = new Person();
            me.FamilyName = "Choi";
            me.GivenName = "Jung";
            me.BirthDate = new DateTime(1989, 1, 3);
            me.FavouriteColor = "Black";
            me.FavouriteNumber = 1;




            return View(me);
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";
            var myContact = new ContactInfo();
            myContact.Email = "JGCHOI@MYSENECA.CA";
            myContact.PhoneNumber ="6478382000";
            myContact.PostalAddress ="20 Graydon Hall";

            return View(myContact);
        }
    }


    public class ContactInfo
    {
        public int id { get; set; }
        public string Email { get; set; }
        public string OtherInfo { get; set; }
        public string PhoneNumber { get; set; }
        public string PostalAddress { get; set; }
        public ContactInfo()
        {
            this.id = 1;
        }
    }
    public class Person
    {
          public Person()
          {
              this.Id = 1;
              this.BirthDate=DateTime.Now;
          }
        public int Id { get; set; }
        public string FamilyName { get; set; }
        public string GivenName { get; set; }
        public DateTime BirthDate { get; set; }
        public int FavouriteNumber { get; set; }
        public string FavouriteColor { get; set; }

        public string FullName()
        {
            return GivenName + " " + FamilyName;
        }
    }
}