using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lab4.Controllers
{
    public class ProductsController : Controller
    {
        private Manager m = new Manager();

        // ############################################################

        //
        // GET: /Products/
        public ActionResult Index()
        {
            // Return all products
            return View(m.GetAllProducts());
        }

        //
        // GET: /Products/Details/5
        public ActionResult Details(int id)
        {
            // Attempt to fetch the object
            var result = m.GetProductById(id);

            // If not found, redirect to the index view
            if(result == null)
            {
                return RedirectToAction("index");
            }
            else
            {
                // Otherwise, return the fetched object in the view
                return View(result);
            }
       
        }

        // ############################################################

        //
        // GET: /Products/Create
        public ActionResult Create()
        {
            // Prepare the data for the view...
            // Create a new ProductAddForm object
            var form = new ProductAddForm();

            // Configure the SelectList properties with data
            form.Size = new SelectList(m.GetProductSizes());
            form.Supplier = new SelectList(m.GetAllSuppliersList(), "Id", "Name");
            
            // Return the object in the view
            return View(form);
        }

        //
        // POST: /Products/Create
        [HttpPost]
        public ActionResult Create(ProductAdd newItem)
        {
            // Model state validity check
            // If not valid, redirect to the index view
            
            if(!ModelState.IsValid)
            {
                return RedirectToAction("index");
            }
            else
            // Otherwise, continue
            {
                // Attempt to add the new item, using the manager method
                var addedItem = m.AddNewProduct(newItem);
              
                
                // If the attempt fails, redirect to the index view
                if (addedItem == null)
                {
                    return RedirectToAction("index");                
                }
                // Otherwise, redirect to the details view for the added object
                else
                {
                    return RedirectToAction("Details", new { id = addedItem.Id });
                }
                
            }
            
         
        }

        // ############################################################

        /*
        //
        // GET: /Products/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        //
        // POST: /Products/Edit/5
        [HttpPost]
        public ActionResult Edit(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add update logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        //
        // GET: /Products/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        //
        // POST: /Products/Delete/5
        [HttpPost]
        public ActionResult Delete(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add delete logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }
        */
    }
}
