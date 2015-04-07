using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lab2.Controllers
{
    public class HomeController : Controller
    {
        //manger object
        private Manager m = new Manager();

        public ActionResult Index()
        {
            return View(m.AllCars);
        }

        public ActionResult Create()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Create(CarAdd newItem)
        {
            if (ModelState.IsValid)
            {
                var addedItem = m.AddCar(newItem);
            }
            else
            {
                return View(newItem);
            }

            return RedirectToAction("index");
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
    }
}