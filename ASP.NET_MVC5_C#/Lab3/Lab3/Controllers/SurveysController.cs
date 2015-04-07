using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lab3.Controllers
{
    public class SurveysController : Controller
    {
        //Manager class
        private Manager m = new Manager();

        // GET: Surveys
        public ActionResult Index()
        {
            return View(m.AllSurveys);
        }

        // GET: Surveys/Details/5
        public ActionResult Details(int id)
        {
            return View(m.GetSurveyById(id));
        }

        // GET: Surveys/Create
        public ActionResult Create()
        {
            var addForm = new SurveyAddForm();
            addForm.Courses = new SelectList(m.UI_Courses());
            addForm.FavouriteTopics = new SelectList(m.UI_FavouriteTopics());
            addForm.PaceOfLearning = new SelectList(m.UI_PaceOfLearning());

            return View(addForm);
        }

        // POST: Surveys/Create
        [HttpPost]
        public ActionResult Create(SurveyAdd newItem)
        {
            SurveyFull addedItem = null;

            // Check that the incoming data is valid
            if (ModelState.IsValid)
            {
                addedItem = m.AddSurvey(newItem);
            }
            else
            {
                // Return the object so the user can edit it correctly
                return View(newItem);
            }

            return RedirectToAction("index");
        }
    }

       
    
}
