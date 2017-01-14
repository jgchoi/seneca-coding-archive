using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment3.Models;

namespace Assignment3.Controllers
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

        public IEnumerable<EmployeeBase> EmployeeGetAll()
        {
            var c = ds.Employees
                .OrderBy(e => e.LastName)
                .ThenBy(e => e.FirstName);

            return Mapper.Map<IEnumerable<EmployeeBase>>(c);
        }

        public IEnumerable<InvoiceBase> InvoiceGetAll()
        {
            var c = ds.Invoices
                .Include("Customer")
                .OrderBy(e => e.InvoiceId);

            return Mapper.Map<IEnumerable<InvoiceBase>>(c);
        }

        public InvoiceBase2 InvoiceGetByIdWithAllInfo(int id)
        {
            var o = ds.Invoices
                .Include("Customer")
                .Include("Customer.Employee")
                .Include("InvoiceLines")
                .Include("InvoiceLines.Track")
                .Include("InvoiceLines.Track.Album")
                .Include("InvoiceLines.Track.Album.Artist")
                .Include("InvoiceLines.Track.MediaType")
                .SingleOrDefault(e => e.InvoiceId == id);

            return (o == null) ? null : Mapper.Map<InvoiceBase2>(o);
        }

        public EmployeeBase2 EmployeeGetByIdWithAllInfo(int id)
        {
            var o = ds.Employees
                .Include("Employee1")
                .Include("Employee2")
                .SingleOrDefault(e => e.EmployeeId == id);

            return (o == null) ? null : Mapper.Map<EmployeeBase2>(o);
        }

        public EmployeeBase EmployeeAdd(EmployeeAdd newItem)
        {
            // Attempt to add the object
            var addedItem = ds.Employees.Add(Mapper.Map<Employee>(newItem));
            if (newItem.Employee2EmployeeId != null)
            {
                var s = ds.Employees.Find(newItem.Employee2EmployeeId);
                if (s != null)
                {
                    addedItem.Employee2 = s;
                }
            }
            ds.SaveChanges();

            // Return the result, or null if there was an error
            return (addedItem == null) ? null : Mapper.Map<EmployeeBase>(addedItem);
        }

        public EmployeeBase EmployeeEditManager(EmployeeEditManager editedItem)
        {
            // Ensure that we can continue
            if (editedItem == null) { return null; }

            // Attempt to fetch the object
            var storedItem = ds.Employees
                .Include("Employee1")
                .Include("Employee2")
                .SingleOrDefault(e => e.EmployeeId == editedItem.EmployeeId);

            var s = ds.Employees
                .Include("Employee1")
                .SingleOrDefault(e => e.EmployeeId == editedItem.Employee2EmployeeId);

            if (storedItem == null || s == null)
            {
                return null;
            }
            else
            {
                // Fetch the object from the data store - ds.Entry(storedItem)
                // Get its current values collection - .CurrentValues
                // Set those to the edited values - .SetValues(editedItem)
                s.Employee1.Remove(storedItem);
                ds.Entry(storedItem).CurrentValues.SetValues(editedItem);
                storedItem.Employee2 = s;

                // The SetValues() method ignores missing properties and navigation properties
                ds.SaveChanges();

                return Mapper.Map<EmployeeBase>(storedItem);
            }
        }

        public EmployeeBase EmployeeEditDirectReport(EmployeeEditDirectReport editedItem)
        {
            // Ensure that we can continue
            if (editedItem == null) { return null; }

            // Attempt to fetch the object
            var storedItem = ds.Employees
                .Include("Employee1")
                .Include("Employee2")
                .SingleOrDefault(e => e.EmployeeId == editedItem.EmployeeId);

            if (storedItem == null)
            {
                return null;
            }
            else
            {
                var newEmployee1 = new HashSet<Employee>();

                foreach (int Employee1EmployeeId in editedItem.Employee1)
                {
                    if (Employee1EmployeeId == editedItem.EmployeeId)
                    {
                        return null;
                    }

                    var d = ds.Employees
                              .Include("Employee1")
                              .Include("Employee2")
                              .SingleOrDefault(e => e.EmployeeId == Employee1EmployeeId);

                    if (d == null)
                    {
                        return null;
                    }

                    newEmployee1.Add(d);
                }

                foreach (var employee1 in storedItem.Employee1)
                {
                    employee1.Employee2 = null;
                }

                foreach (var employee1 in newEmployee1)
                {
                    employee1.Employee2 = storedItem;
                }

                //Assignm new direct report list
                storedItem.Employee1 = newEmployee1;

                // The SetValues() method ignores missing properties and navigation properties
                ds.SaveChanges();

                return Mapper.Map<EmployeeBase>(storedItem);
            }
        }
    }
}

