using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lab5.Controllers
{
    public class ArtistsController : Controller
    {
        private Manager m = new Manager();
        // GET: Artists
        public ActionResult Index()
        {
            return View(m.AllArtists());
        }



        // GET: Artists/Create
        public ActionResult Create()
        {
            //AddForm Model
            var form = new ArtistAddForm();

            //Set default value & SelectList
            form.BirthOrStartDate = DateTime.Now.AddYears(-30);

            form.StartDecade = ((int)((DateTime.Now.Year - 10) / 10)) * 10;
            form.Genre = new SelectList(m.AllGenres());
            return View(form);
        }

        // POST: Artists/Create
        [HttpPost]
        public ActionResult Create(ArtistAdd newItem)
        {

            if (!ModelState.IsValid)
            {
                return RedirectToAction("error");
            }
            else
            {
                var addedItem = m.AddArtists(newItem);
                return RedirectToAction("index");

            }
        }
    }
}
