using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lab2.Controllers
{
    public class CarAdd
    {
        public String Manufacturer { get; set; }
        public String Model { get; set; }
        public int MSRP { get; set; }
        public int Year { get; set; }

    }

    public class CarFull : CarAdd
    {
        public int Id { get; set; }
    }
}