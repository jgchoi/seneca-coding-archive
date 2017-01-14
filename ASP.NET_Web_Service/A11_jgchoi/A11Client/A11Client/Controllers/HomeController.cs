using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Web;
using System.Web.Mvc;

namespace A11Client.Controllers
{

    public class HomeController : Controller
    {
        private Manager m = new Manager();

        public ActionResult Index()
        {
            ViewBag.Title = "Home Page";

            return View();
        }

        public ActionResult Login()
        {
            return View();
        }

        public async Task<ActionResult> AppClaims()
        {
            // Attempt to fetch the collection
            var c = await m.AppClaimGetAll();

                return View(c);
        }

        public async Task<ActionResult> Users()
        {
            // Attempt to fetch the collection
            var c = await m.UserGetAll();

            return View(c);
        }

        // POST: Customers/Create
        [HttpPost]
        public ActionResult Login(LoginItems newItem)
        {

            // Validate the input
            if (!ModelState.IsValid)
            {
                return View(newItem);
            }

            // Process the input
            var addedItem = m.GetAccessToken(newItem);

            if (addedItem.Result == false)
            {
                return View(newItem);
            }
            else
            {
                return RedirectToAction("index");
            }
        }
    }
}
