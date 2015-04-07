using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lab5.Controllers
{
    public class SongsController : Controller
    {
        private Manager m = new Manager();
        // GET: Songs
        public ActionResult Index()
        {


            return View(m.AllSongs());
        }

        // GET: Songs/Create
        public ActionResult Create()
        {
            var addForm = new SongAddForm();
            addForm.AlbumId = new SelectList(m.AllAlbumsList(), "Id", "AlbumAndArtist");
            addForm.Genre = new SelectList(m.AllGenres());
            addForm.SingleReleaseDate = DateTime.Now.AddYears(-1);

            return View(addForm);
        }

        // POST: Songs/Create
        [HttpPost]
        public ActionResult Create(SongAdd newItem)
        {
            if (!ModelState.IsValid)
            {
                return RedirectToAction("error");
            }
            else
            {
                var addedItem = m.AddSong(newItem);
                return RedirectToAction("index");

            }
        }
    }
}
