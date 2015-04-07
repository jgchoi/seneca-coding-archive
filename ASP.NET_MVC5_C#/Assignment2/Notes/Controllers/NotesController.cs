using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Notes.Controllers
{
    [Authorize]
    public class NotesController : Controller
    {
        private Manager m = new Manager();

        // GET: Notes
        [Authorize(Roles = "Administrator")]
        public ActionResult Index()
        {
            throw new NotImplementedException();
        }

        // GET: Notes/Details/5
        public ActionResult Details(int? id)
        {
            // Determine whether we can continue, non-null id
            if (!id.HasValue) { return HttpNotFound(); }

            // Attempt to fetch the object
            else
            {
                var fetchedObject = m.GetNoteForAuthenticatedEmployee((int)id);
                if (fetchedObject == null)
                    return HttpNotFound();
                else
                    // Present the view
                    return View(fetchedObject);
            }

        }

        // GET: Notes/Create/{id}
        public ActionResult Create()
        {
            int? emp_id = m.GetEmployeeIdForUserName(User.Identity.Name);

            // Validate the user name 
            if (!emp_id.HasValue)
            {  // If validation fails, exit
                return HttpNotFound();
            }
            else
            { // Otherwise, continue...
                // Create and configure an 'add form'
                var addForm = new NoteAddForm();
                addForm.EmployeeId = (int)emp_id;
                return View(addForm);
            }
        }

        // POST: Notes/Create
        [HttpPost]
        [ValidateInput(false)]
        public ActionResult Create(NoteAdd newItem)
        {
            // Standard 'add new' handling
            // Including checking the ModelState
            if (!ModelState.IsValid)
            {
                // If there's a problem with the form data postback, redisplay the form
                var addForm = new NoteAddForm();
                addForm.EmployeeId = newItem.EmployeeId;
                addForm.NoteText = newItem.NoteText;
                addForm.Title = newItem.Title;
                // If there's a problem with the form data postback, redisplay the form

                return View(addForm);
            }
            else
            {
                // Otherwise, whether successful or not, redirect back to the employee's
                // details view
                var addedItem = m.AddNoteForAuthenticatedEmployee(newItem);
                if (addedItem == null)
                { return HttpNotFound(); }

                return RedirectToAction("Details", "Employees", new { id = addedItem.EmployeeId });
            }
        }


        // GET: Notes/Edit/5
        public ActionResult Edit(int? id)
        {
            // Determine whether we can continue, non-null id
            if (!id.HasValue)
            { return HttpNotFound(); }
            // Attempt to fetch the object
            else
            {
                var fetchedObject = AutoMapper.Mapper.Map<NoteEditForm>(m.GetNoteForAuthenticatedEmployee((int)id));
                if (fetchedObject == null)
                { return HttpNotFound(); }
                else
                {
                    fetchedObject.NoteId = (int)id;

                    return View(fetchedObject);
                }
            }
        }

        // POST: Notes/Edit/5
        [HttpPost]
        [ValidateInput(false)]
        public ActionResult Edit(int id, NoteEdit newItem)
        {
            if (!ModelState.IsValid)
            {
                // If there's a problem with the form data postback, redisplay the form
                var form = AutoMapper.Mapper.Map<NoteEditForm>(newItem);
                // If there's a problem with the form data postback, redisplay the form
                return View(form);
            }
            else
            {
                var updatedItem = m.UpdateNoteForAuthenticatedEmployee(newItem);
                return RedirectToAction("Details", "Employees", new { id = updatedItem.EmployeeId });
            }
        }

        // GET: Notes/Delete/5
        public ActionResult Delete(int? id)
        {

            // Determine whether we can continue, non-null id
            if (!id.HasValue)
            { return HttpNotFound(); }
            // Attempt to fetch the object
            else
            {
                var fetchedObject = AutoMapper.Mapper.Map<NoteBase>(m.GetNoteForAuthenticatedEmployee((int)id));
                if (fetchedObject == null)
                { return HttpNotFound(); }
                else
                {
                    return View(fetchedObject);
                }
            }
        }

        // POST: Notes/Delete/5
        [HttpPost]
        public ActionResult Delete(int? id, NoteEdit deletedItem)
        {
            if (!id.HasValue)
            { return HttpNotFound(); }

            var empy = m.deleteNoteById((int)id);
            return RedirectToAction("Details", "Employees", new { id = empy.Id });

        }
    }
}
