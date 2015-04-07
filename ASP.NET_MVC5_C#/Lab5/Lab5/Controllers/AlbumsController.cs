using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lab5.Controllers
{
    public class AlbumsController : Controller
    {
        private Manager m = new Manager();
        // GET: Albums
        public ActionResult Index()
        {
            return View(m.AllAlbums());
        }



        // GET: Albums/Create
        public ActionResult Create()
        {
            var addForm = new AlbumAddForm();
            addForm.ArtistId = new SelectList(m.AllArtistsList(), "Id", "Name");
            addForm.Genre = new SelectList(m.AllGenres());
            addForm.ReleaseDate = DateTime.Now.AddYears(-1);

            return View(addForm);
        }

        // POST: Albums/Create
        [HttpPost]
        public ActionResult Create(AlbumAdd newItem)
        {
            if (!ModelState.IsValid)
            {
                return RedirectToAction("error");
            }
            else
            {
                var addedItem = m.AddAlbum(newItem);
                return RedirectToAction("index");

            }
        }

    }
}
