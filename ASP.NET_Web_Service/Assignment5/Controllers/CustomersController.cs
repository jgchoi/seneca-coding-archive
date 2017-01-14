using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace Assignment5.Controllers
{
    public class CustomersController : ApiController
    {
        private Manager m = new Manager();
        /// <summary>
        /// All cusomters, ordered by customer name
        /// </summary>
        /// <returns>Collection of CustomerBase (linked) objects</returns>
        // GET: api/Customers
        public IHttpActionResult Get()
        {
            // Get all
            var c = m.CustomerGetAll();

            // Create a hypermedia representation
            CustomersLinked result = new CustomersLinked
                (Mapper.Map<IEnumerable<CustomerWithLink>>(c));

            return Ok(result);
        }

        /// <summary>
        /// Specific customers details
        /// </summary>
        /// <param name="id">Customer Id</param>
        /// <returns>Details about customers information</returns>
        // GET: api/Customers/5
        public IHttpActionResult Get(int? id)
        {
            // Attempt to fetch the object
            var o = m.CustomerGetById(id.GetValueOrDefault());

            // Continue?
            if (o == null)
            {
                return NotFound();
            }
            else
            {
                // Create a hypermedia representation
                CustomerLinked result = new CustomerLinked
                    (Mapper.Map<CustomerWithLink>(o));

                return Ok(result);
            }
        }

        /// <summary>
        /// Add new customer info
        /// </summary>
        /// <param name="newItem">Json structured customer information see tempate for details</param>
        /// <returns>Newly created custoemr information</returns>
        // POST: api/Customers
        public IHttpActionResult Post([FromBody]CustomerAdd newItem)
        {
            // Ensure that the URI is clean (and does not have an id parameter)
            if (Request.GetRouteData().Values["id"] != null) { return BadRequest("Invalid request URI"); }

            // Ensure that a "newItem" is in the entity body
            if (newItem == null) { return BadRequest("Must send an entity body with the request"); }

            // Ensure that we can use the incoming data
            if (!ModelState.IsValid) { return BadRequest(ModelState); }

            // Attempt to add the new object
            var addedItem = m.CustomerAdd(newItem);

            // Continue?
            if (addedItem == null) { return BadRequest("Cannot add the object"); }

            // HTTP 201 with the new object in the entity body
            // Notice how to create the URI for the Location header
            var uri = Url.Link("DefaultApi", new { id = addedItem.CustomerId });

            // Create a hypermedia representation

            // ****** Error during automapping *******

            //CustomerLinked result = new CustomerLinked(Mapper.Map<CustomerWithLink>(addedItem));

            //return Created(uri, result);
            // ******** error end ************
            return Created(uri, addedItem);
        }

        /// <summary>
        /// Update specific customer's contact information
        /// </summary>
        /// <param name="id">Customer Id</param>
        /// <param name="editedItem">Json form of new contact info</param>
        /// <returns>Status 200 if success</returns>
        // PUT: api/Customers/5
        public IHttpActionResult Put(int? id, [FromBody]CustomerEditContactInfo editedItem)
        {
            // Ensure that an "editedItem" is in the entity body
            if (editedItem == null)
            {
                return BadRequest("Must send an entity body with the request");
            }

            // Ensure that the id value in the URI matches the id value in the entity body
            if (id.GetValueOrDefault() != editedItem.CustomerId)
            {
                return BadRequest("Invalid data in the entity body");
            }

            // Ensure that we can use the incoming data
            if (ModelState.IsValid)
            {
                // Attempt to update the item
                var changedItem = m.CustomerEditContactInfo(editedItem);

                // Notice the ApiController convenience methods
                if (changedItem == null)
                {
                    // HTTP 400
                    return BadRequest("Cannot edit the object");
                }
                else
                {
                    // Create a hypermedia representation
                    CustomerLinked result = new CustomerLinked
                        (Mapper.Map<CustomerWithLink>(changedItem));

                    // HTTP 200 with the changed item in the entity body
                    return Ok(result);
                }
            }
            else
            {
                return BadRequest(ModelState);
            }
        }

        /// <summary>
        /// Set a support rep
        /// </summary>
        /// <param name="id">Customer ID </param>
        /// <param name="editedItem"> json contains customerId and employeeId</param>
        /// <returns>Return status 200 if success</returns>
        // PUT: api/customers/{id}/setsupportrep
        [Route("api/customers/{id}/setsupportrep")]
        public IHttpActionResult PutChangeSupportRep(int? id, [FromBody]CustomerEditSupportRep editedItem)
        {
            // Ensure that an "editedItem" is in the entity body
            if (editedItem == null)
            {
                return BadRequest("Must send an entity body with the request");
            }

            // Ensure that the id value in the URI matches the id value in the entity body
            if (id.GetValueOrDefault() != editedItem.CustomerId)
            {
                return BadRequest("Invalid data in the entity body");
            }

            // Ensure that we can use the incoming data
            if (ModelState.IsValid)
            {
                // Attempt to update the item
                var changedItem = m.CustomerEditSupportRep(editedItem);

                // Notice the ApiController convenience methods
                if (changedItem == null)
                {
                    // HTTP 400
                    return BadRequest("Cannot edit the object");
                }
                else
                {
                    // HTTP 200 with the changed item in the entity body
                    return Ok();
                }
            }
            else
            {
                return BadRequest(ModelState);
            }
        }
    }
}
