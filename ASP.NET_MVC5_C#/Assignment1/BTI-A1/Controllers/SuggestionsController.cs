using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace BTI_A1.Controllers
{
    public class SuggestionsController : Controller
    {
        private Manager m = new Manager();
        // GET: Suggestions
        public ActionResult Index()
        {
            return View(m.GetAllSuggestions());
        }

        // GET: Suggestions/Details/5
        public ActionResult Details(int? id)
        {

            if (!id.HasValue) { return HttpNotFound(); }

            var fetchedObject = m.GetSuggestionByIdWithFollowUps(id.Value);

            if (fetchedObject == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(fetchedObject);
            }
        }

        // GET: Suggestions/Create
        public ActionResult Create()
        {
            //Create Addform object
            var form = new SuggestionAddForm();

            //Setting seletlist
            form.CourseId = new SelectList(m.GetAllCoursesList(), "Id", "CodeAndName");
            form.ProgramId = new SelectList(m.GetAllProgramsList(), "Id", "CodeAndName");

            return View(form);
        }

        // POST: Suggestions/Create
        [HttpPost, ValidateInput(false)]
        public ActionResult Create(SuggestionAdd newItem)
        {
            if (!ModelState.IsValid)
            {
                return HttpNotFound();
            }
            else
            {
                var addedItem = m.AddNewSuggestion(newItem);

                if (addedItem == null)
                {
                    return HttpNotFound();
                }
                else
                {
                    return RedirectToAction("index");
                }
            }

        }

        // GET: Suggestions/Edit/5
        public ActionResult Edit(int? id)
        {
            if (!id.HasValue) { return HttpNotFound(); }

            var fetchedObject = m.GetSuggestionById(id.Value);

            if (fetchedObject == null)
            {
                return HttpNotFound();
            }
            else
            {
                var editForm = AutoMapper.Mapper.Map<SuggestionEditForm>(fetchedObject);
            

                return View(editForm);

            }


        }

        // POST: Suggestions/Edit/5
        [HttpPost, ValidateInput(false)]
        public ActionResult Edit(int id, SuggestionEdit newItem)
        {
            //What is this single & means?
            if(ModelState.IsValid & id == newItem.Id)
            {
                var editedItem = m.EditSuggestion(newItem);

                if(editedItem == null)
                {
                    var editedForm = AutoMapper.Mapper.Map<SuggestionEditForm>(newItem);
                    ModelState.AddModelError("modelState", "There was an error. (The edited data could not be saved.)");
                    return View(editedForm);
                }
                else
                {
                    return RedirectToAction("details", new { id = editedItem.Id });
                }
            }
            else
            {
                var editedForm = AutoMapper.Mapper.Map<SuggestionEditForm>(newItem);
                ModelState.AddModelError("modelState", "There was an error. (The edited data could not be saved.)");
                return View(editedForm);
            }
        }

        // GET: Suggestions/Delete/5
        public ActionResult Delete(int? id)
        {
            if (!id.HasValue) { return HttpNotFound(); }

            var fetchedObject = m.GetSuggestionById(id.Value);

            if (fetchedObject == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(fetchedObject);
            }
        }

        // POST: Suggestions/Delete/5
        [HttpPost]
        public ActionResult Delete(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add delete logic here
                m.deleteSuggestionById(id);
                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }
    }
}
