using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Web;
using System.Web.Mvc;

namespace Assign12Client.Controllers
{
    public class HomeController : Controller
    {
        private Manager m = new Manager();
        public ActionResult Index()
        {
            ViewBag.Title = "Home Page";

            return View();
        }

        public async Task<ActionResult> AllCourses()
        {
            // Attempt to fetch the collection
            var c = await m.GetAllCourses();
            c.OrderBy(course => course.CourseName);

            return View(c);
        }

        public ActionResult Outline(string id)
        {
           
            var x = m.SubjectOutlineByCode(id);

            return View(x);
        }
    }
}
