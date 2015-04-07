using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace BTI_A1.Controllers
{
    public class DataImportsController : Controller
    {
        private Manager m = new Manager();

        // GET: DataImports
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult ReadPrograms()
        {
            return View(m.ReadProgramsFromCSV());
        }
        public ActionResult LoadPrograms()
        {
            m.LoadProgramFromCSV();
 
            return RedirectToAction("ViewPrograms");
        }
        public ActionResult DeletePrograms()
        {
            //Clear database
            m.DeletePrograms();
            return RedirectToAction("ViewPrograms");
        }
        public ActionResult ViewPrograms()
        {
            var fetachedObject = m.GetAllPrograms();
            if (fetachedObject == null)
            {
                return View("index");
            }
            else
            {
                return View(fetachedObject);
            }
        }

        public ActionResult ReadCourses()
        {
            return View(m.ReadCoursesFromCSV());
        }
        public ActionResult LoadCourses()
        {
            m.LoadCourseFromCSV();

            return RedirectToAction("ViewCourses");
        }
        public ActionResult DeleteCourses()
        {
            m.DeleteCourses();
            return RedirectToAction("ViewCourses");
        }
        public ActionResult ViewCourses()
        {
            var fetachedObject = m.GetAllCourses();
            if(fetachedObject == null)
            {
                return View("index");
            }
            else
            {
                return View(fetachedObject);
            }
        }
    }
}