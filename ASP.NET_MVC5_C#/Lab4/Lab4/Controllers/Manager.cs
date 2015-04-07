using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using Lab4.Models;
using System.Web.Mvc;
using AutoMapper;

namespace Lab4.Controllers
{
    public class Manager
    {
        private DataContext ds = new DataContext();

        public List<string> GetProductSizes()
        {
            // Return a collection of strings
            var result = new List<string>
            {
                "Small",
                "Medium",
                "Large"
            };

            return result;
         
        }

        // ############################################################
        // Supplier - get all, get all for select list

        public IEnumerable<SupplierBase> GetAllSuppliers()
        {
            // Fetch from the data store
            var fetchedObjects = ds.Suppliers.OrderBy(nm => nm.Name);

            // Prepare the return result
            // Return the result
            return Mapper.Map<IEnumerable<SupplierBase>>(fetchedObjects);
        }

        // Get list
        public IEnumerable<SupplierList> GetAllSuppliersList()
        {
            // Fetch from the data store
            var fetchedObjects = ds.Suppliers.OrderBy(nm => nm.Name);
            
            // Prepare the return result
            // Return the result
            return Mapper.Map<IEnumerable<SupplierList>>(fetchedObjects);
        }

        // ############################################################
        // Product - get all, get one, add new

        public IEnumerable<ProductBase> GetAllProducts()
        {
            // Fetch from the data store
            var fetchedObjects = ds.Products.Include("Supplier").OrderBy(nm => nm.Name);

            // Prepare the return result
            IEnumerable<ProductBase> result;
            result = Mapper.Map<IEnumerable<ProductBase>>(fetchedObjects);

            // Return the result
            return result;
        }

        public ProductBase GetProductById(int id)
        {
            // Fetch from the data store
            Product fetchedObject = ds.Products.Include("Supplier").Single(i => i.Id == id);
            ProductBase result = null;
            // If not found, return null
            if (fetchedObject == null)
            {
                return null;
            }
            else
            // Otherwise, continue
            {
                // Prepare the return result
                result = Mapper.Map<ProductBase>(fetchedObject);
                result.SupplierName = fetchedObject.Supplier.Name;

            }
            
            // Return the result
            return result;
        }

        public ProductBase AddNewProduct(ProductAdd newItem)
        {
            // Attempt to fetch the supplier object
            var supplier = ds.Suppliers.Find(newItem.SupplierId);
            ProductBase result;
            if(supplier != null)
            {
                // Otherwise, continue
                // Create a new design model object
                var addedItem = new Product();

                // Its properties come from the passed-in 'newItem' object
                addedItem = Mapper.Map<Product>(newItem);

                // Remember to configure the Supplier property correctly
                addedItem.Supplier = supplier;
                // Add to the peristent store, and save changes
                ds.Products.Add(addedItem);
                ds.SaveChanges();
                // Prepare the return result
                result = Mapper.Map<ProductBase>(addedItem);
            }   
            else
            { 
                // If that fails, return null
                return null;
            }

            // Return the result
            return result;
           
        }

    }

}
