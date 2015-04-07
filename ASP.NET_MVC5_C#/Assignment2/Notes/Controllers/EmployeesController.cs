using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Claims;
using System.Web;
using System.Web.Mvc;

namespace Notes.Controllers
{
    [Authorize]
    public class EmployeesController : Controller
    {
        private Manager m = new Manager();

        // GET: Employees
        [Authorize(Roles = "Administrator")]
        public ActionResult Index()
        {
            return View(m.GetAllEmployees());
        }

        // GET: Employees/DetailsByUserName/{username}
        // The purpose of this method is to support a username lookup,
        // but as you can see, it simply redirects with the user identifier
        // to the next method
        public ActionResult DetailsByUserName(string username)
        {
            // Determine whether we can continue, non-null username
            if (username != null)
            {
                // Attempt to fetch the object
                int? userId = m.GetEmployeeIdForUserName(username);
                if (userId != null)
                {
                    // If found, redirect to the Details method, specifying the Employee Id
                    return RedirectToAction("Details", new { id = userId });
                }
            }
            throw new NotImplementedException();
        }

        // GET: Employees/Details/5
        public ActionResult Details(int? id)
        {
            if (id != null)
            {
                var fetchedObject = m.GetEmployeeByIdWithAssociatedData((int)id);

                if (fetchedObject != null)
                {
                    //Check manager
                    if (fetchedObject.Manager != null)
                        fetchedObject.ManagerFullName = fetchedObject.Manager.FullName;
                    return View(fetchedObject);

                }
                else
                    throw new NotImplementedException();
            }
            else
                throw new NotImplementedException();

        }

        // GET: Employees/ChooseDirectReports/5
        // Sends the form to enable a manager to select their direct reports
        public ActionResult ChooseDirectReports(int? id)
        {
            // Determine whether we can continue, non-null id
            if (id == null)
            {
                throw new NotImplementedException();
            }
            //else if(User.IsInRole("Manager"))
            else if ((User as ClaimsPrincipal).HasClaim(ClaimTypes.Role, "Manager") == true)
            {
                // Verify that the security context user has the 'Manager' role claim
                // e.g. (User as ClaimsPrincipal).HasClaim(ClaimTypes.Role, "Manager")
                // Prepare and configure a form to send to the view
                // Present the view
                var form = new EmployeeDirectReportsForm();
                form.Id = (int)id;
                form.Employees = new SelectList(m.GetAllEmployeesNoManager(), "Id", "FullName");

                return View(form);
            }

            //Error
            throw new NotImplementedException();


        }

        // POST: Employees/ChooseDirectReports/5
        // Handles the selection of direct reports
        [HttpPost]
        public ActionResult ChooseDirectReports(int? id, EmployeeDirectReports newItem)
        {
            if (ModelState.IsValid & id == newItem.Id)
            {
                // Attempt to perform the task
                var addedItem = m.ConfigureDirectReports(newItem);

                if (addedItem == null)
                {
                    // There was a problem, just do a redirect
                    return RedirectToAction("Details", new { id = id });
                }
                else
                {
                    // Maybe return to a results page
                    ViewBag.managerId = id;
                    return View("DirectReports", addedItem);
                }
            }
            else
            {
                // There was a problem, just do a redirect
                return RedirectToAction("Details", new { id = id });
            }
        }



    }
}
