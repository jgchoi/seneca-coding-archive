using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment5.Models;

namespace Assignment5.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        public Manager()
        {
            // If necessary, add constructor code here

            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            ds.Configuration.LazyLoadingEnabled = false;
        }
        public IEnumerable<InvoiceBase> InvoiceGetAll()
        {
            // Fetch the collection
            var c = ds.Invoices.OrderBy(e => e.InvoiceDate);

            // Return the results as a collection based on a resource model class
            return Mapper.Map<IEnumerable<InvoiceBase>>(c);
        }


        public IEnumerable<CustomerBase> CustomerGetAll()
        {
            // Fetch the collection
            var c = ds.Customers
                    .Include("Employee");

            // Return the results as a collection based on a resource model class
            return Mapper.Map<IEnumerable<CustomerBase>>(c);
        }

        public CustomerBase CustomerGetById(int id)
        {
            // Attempt to fetch the object
            var o = ds.Customers
                    .Include("Employee")
                    .SingleOrDefault(e => e.CustomerId == id);

            // Return the result, or null if not found
            return (o == null) ? null : Mapper.Map<CustomerBase>(o);
        }

        public CustomerBase CustomerAdd(CustomerAdd newItem)
        {
            // Attempt to add the object
            var addedItem = ds.Customers.Add(Mapper.Map<Customer>(newItem));
            ds.SaveChanges();

            // Return the result, or null if there was an error
            return CustomerGetById(addedItem.CustomerId);
        }

        public CustomerBase CustomerEditContactInfo(CustomerEditContactInfo editedItem)
        {
            // Ensure that we can continue
            if (editedItem == null) { return null; }

            // Attempt to fetch the object
            var storedItem = ds.Customers
                    .Include("Employee")
                    .SingleOrDefault(e => e.CustomerId == editedItem.CustomerId);

            if (storedItem == null)
            {
                return null;
            }
            else
            {
                // Fetch the object from the data store - ds.Entry(storedItem)
                // Get its current values collection - .CurrentValues
                // Set those to the edited values - .SetValues(editedItem)
                ds.Entry(storedItem).CurrentValues.SetValues(editedItem);
                // The SetValues() method ignores missing properties and navigation properties
                ds.SaveChanges();

                return Mapper.Map<CustomerBase>(storedItem);
            }
        }

        public CustomerBase CustomerEditSupportRep(CustomerEditSupportRep editedItem)
        {
            // Ensure that we can continue
            if (editedItem == null) { return null; }

            // Attempt to fetch the object
            var storedItem = ds.Customers
                    .Include("Employee")
                    .SingleOrDefault(e => e.CustomerId == editedItem.CustomerId);

            var s = ds.Employees.Find(editedItem.SupportRepId);

            if (storedItem == null || s == null)
            {
                return null;
            }
            else
            {
                // Fetch the object from the data store - ds.Entry(storedItem)
                // Get its current values collection - .CurrentValues
                // Set those to the edited values - .SetValues(editedItem)

                ds.Entry(storedItem).CurrentValues.SetValues(editedItem);
                storedItem.Employee = s;

                // The SetValues() method ignores missing properties and navigation properties
                ds.SaveChanges();

                return Mapper.Map<CustomerBase>(storedItem);
            }
        }

    }
}