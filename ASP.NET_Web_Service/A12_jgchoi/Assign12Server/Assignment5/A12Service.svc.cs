using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;
using Assignment5.Controllers;
using System.ComponentModel.DataAnnotations;
using AutoMapper;

namespace Assignment5
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "A12Service" in code, svc and config file together.
    // NOTE: In order to launch WCF Test Client for testing this service, please select A12Service.svc or A12Service.svc.cs at the Solution Explorer and start debugging.
    public class A12Service : IA12Service
    {
        private Manager m = new Manager();
        public CustomerWithData CustomerAdd(CustomerAdd newItem)
        {
            // Ensure that a "newItem" is in the entity body
            if (newItem == null)
            {
                return null;
            }

            // Ensure that we can use the incoming data

            // Attention 11 - We do not have access to ModelState in this kind of class
            // However, we can add it in...

            var vc = new ValidationContext(newItem, null, null);
            var modelStateIsValid = Validator.TryValidateObject(newItem, vc, null, true);

            if (modelStateIsValid)
            {
                // Attempt to add the new object
                var addedItem = m.CustomerAdd(newItem);

                // Notice the ApiController convenience methods
                if (addedItem == null)
                {
                    return null;
                }
                else
                {
      
                    return addedItem;
                }
            }
            else
            {
                return null;
            }
        }

        public CustomerWithData CustomerById(int? id)
        {
            // Determine whether we can continue
            if (!id.HasValue) { return null; }

            // Fetch the object, so that we can inspect its value
            var o = m.CustomerGetById(id.Value);

            if (o == null)
            {
                return null;
            }
            else
            {
                return o;
            }
        }

        public CustomerWithData CustomerEditAddress(CustomerEditAddress editedItem)
        {
            // Ensure that an "editedItem" is in the entity body
            if (editedItem == null)
            {
                return null;
            }

            // Ensure that we can use the incoming data
            var vc = new ValidationContext(editedItem, null, null);
            var modelStateIsValid = Validator.TryValidateObject(editedItem, vc, null, true);

            if (modelStateIsValid)
            {
                // Attempt to update the item
                var changedItem = m.CustomerEditAddress(editedItem);

                // Notice the ApiController convenience methods
                if (changedItem == null)
                {
                    // HTTP 400
                    return null;
                }
                else
                {
 
                    return changedItem;
                }
            }
            else
            {
                return null;
            }
        }

        public IEnumerable<CustomerWithData> CustomerGetAll()
        {
            return m.CustomerGetAll();
        }

        public void CustomerSetSupportRep(CustomerSupportRep item)
        {
            // Ensure that an "editedItem" is in the entity body
            if (item == null) { return; }

            var vc = new ValidationContext(item, null, null);
            var modelStateIsValid = Validator.TryValidateObject(item, vc, null, true);

            // Ensure that we can use the incoming data
            if (modelStateIsValid)
            {
                // Attempt to update the item
                m.CustomerSetSupportRep(item);
            }
            else
            {
                return;
            }
        }

        public IEnumerable<InvoiceWithData> InvoiceGetAll()
        {
            return m.InvoiceGetAll();
        }

        CustomerWithData IA12Service.CustomerEditAddress(CustomerEditAddress editedItem)
        {
            // Ensure that an "editedItem" is in the entity body
            if (editedItem == null)
            {
                return null;
            }

  

            var vc = new ValidationContext(editedItem, null, null);
            var modelStateIsValid = Validator.TryValidateObject(editedItem, vc, null, true);

            // Ensure that we can use the incoming data
            if (modelStateIsValid)
            {
                // Attempt to update the item
                var changedItem = m.CustomerEditAddress(editedItem);

                // Notice the ApiController convenience methods
                if (changedItem == null)
                {
                    // HTTP 400
                    return null;
                }
                else
                {
          

                    // HTTP 200 with the changed item in the entity body
                    return changedItem;
                }
            }
            else
            {
                return null;
            }
        }
    }
}
