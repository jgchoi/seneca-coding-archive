using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace Assignment1.Controllers
{
    public class SmartphonesController : ApiController
    {
        private Manager m = new Manager();

        // GET: api/Smartphones
        public IHttpActionResult Get()
        {
            var result = m.SmartphoneGetAll();
            return Ok(result);
        }

        // GET: api/Smartphones/5
        public IHttpActionResult Get(int id)
        {
            var result = m.SmartphoneGetById(id);

            if (result == null)
            {
                return NotFound();
            }
            else
            {
                return Ok(result);
            }
        }

        // POST: api/Smartphones
        public IHttpActionResult Post([FromBody]SmartphoneAdd newItem)
        {
            // Ensure that the URI is clean (and does not have an id parameter)
            if (Request.GetRouteData().Values["id"] != null) { return BadRequest("Invalid request URI"); }

            // Ensure that a "newItem" is in the entity body
            if (newItem == null) { return BadRequest("Must send an entity body with the request"); }

            // Ensure that we can use the incoming data
            if (!ModelState.IsValid) { return BadRequest(ModelState); }

            // Attempt to add the new item...
            var result = m.SmartphoneAdd(newItem);

            //Check if add new item is successfuly, if not return BadRequest
            if (result == null) { return BadRequest("Error occured while creating new item"); }

            var uri = Url.Link("DefaultApi", new { id = result.Id });

            return Created(uri, result);
        }

        // PUT: api/Smartphones/5
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE: api/Smartphones/5
        public void Delete(int id)
        {
        }
    }
}
