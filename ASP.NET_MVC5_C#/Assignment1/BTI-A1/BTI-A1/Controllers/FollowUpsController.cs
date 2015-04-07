using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace BTI_A1.Controllers
{
    public class FollowUpsController : Controller
    {
        private Manager m = new Manager();
        // GET: FollowUps
        public ActionResult Index()
        {
            return View(m.GetAllFollowUps());
        }

        // GET: FollowUps/Details/5
        public ActionResult Details(int? id)
        {

            if (!id.HasValue) { return HttpNotFound(); }

            var fetchedObject = m.GetFollowUpByIdWithSuggestion(id.Value);

            if (fetchedObject == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(fetchedObject);
            }
        }

        // GET: FollowUps/Create
        public ActionResult Create()
        {
            //Create Addform object
            var form = new FollowUpAddForm();

            //Setting seletlist
            form.SuggestionId = new SelectList(m.GetAllSuggestionsList(), "Id", "Title");

            return View(form);
        }

        // POST: FollowUps/Create
        [HttpPost, ValidateInput(false)]
        public ActionResult Create(FollowUpAdd newItem)
        {
            if (!ModelState.IsValid)
            {
                return HttpNotFound();
            }
            else
            {
                var addedItem = m.AddNewFollowUp(newItem);
                if(addedItem == null)
                {
                    return HttpNotFound();
                }
                else
                {
                    return RedirectToAction("index");
                }
            }
        }

        // POST: Followups/Edit/5
        public ActionResult Edit(int? id)
        {
            if (!id.HasValue) { return HttpNotFound(); }

            var fetchedObject = m.GetFollowUpByIdWithSuggestion(id.Value);

            if (fetchedObject == null)
            {
                return HttpNotFound();
            }
            else
            {
                var editForm = AutoMapper.Mapper.Map<FollowUpEditForm>(fetchedObject);

                return View(editForm);

            }


        }

        // POST: Followups/Edit/5
        [HttpPost, ValidateInput(false)]
        public ActionResult Edit(int id, FollowUpEdit newItem)
        {
            //What is this single & means?
            if (ModelState.IsValid & id == newItem.Id)
            {
                var editedItem = m.EditFollowUp(newItem);

                if (editedItem == null)
                {
                    var editedForm = AutoMapper.Mapper.Map<FollowUpEditForm>(newItem);
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
                var editedForm = AutoMapper.Mapper.Map<FollowUpEditForm>(newItem);
                ModelState.AddModelError("modelState", "There was an error. (The edited data could not be saved.)");
                return View(editedForm);
            }
        }

        // GET: FollowUps/Delete/5
        public ActionResult Delete(int? id)
        {
            if (!id.HasValue) { return HttpNotFound(); }

            var fetchedObject = m.GetFollowUpByIdWithSuggestion(id.Value);

            if(fetchedObject == null)
            {
                return HttpNotFound();
            }
            else
            {
                return View(fetchedObject);
            }
        }

        // POST: FollowUps/Delete/5
        [HttpPost]
        public ActionResult Delete(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add delete logic here
                m.deleteFollowUpById(id);
                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }
    }
}
