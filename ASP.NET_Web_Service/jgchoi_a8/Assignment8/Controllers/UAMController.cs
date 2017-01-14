using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace Assignment8.Controllers
{
    // UAM = User Account Management

    [Authorize]
    public class UAMController : ApiController
    {
        // Reference
        private Manager m = new Manager();

        // GET: api/UAM
        public IHttpActionResult Get()
        {
            return Ok(m.UAGetAll());
        }

        // GET: api/UAM/UserId/7d20db02-48ae-4593-8a58-bdb299fd0d34/find
        [Route("api/UAM/userid/{userId}/find")]
        public IHttpActionResult GetById(string userId = "")
        {
            // Attempt to fetch the object
            var o = m.UAGetOneById(userId);

            // Continue?
            if (o == null)
            {
                return NotFound();
            }
            else
            {
                return Ok(o);
            }
        }

        // GET: api/UAM/Email/user123@example.com/find
        [Route("api/UAM/email/{email}/find")]
        public IHttpActionResult GetByEmail(string email = "")
        {
            // Attempt to fetch the object
            var o = m.UAGetOneByEmail(email);

            // Continue?
            if (o == null)
            {
                return NotFound();
            }
            else
            {
                return Ok(o);
            }
        }

        // GET: api/UAM/Email/Smith/find
        [Route("api/UAM/surname/{surname}/find")]
        public IHttpActionResult GetBySurname(string surname = "")
        {
            return Ok(m.UAGetAllBySurname(surname));
        }

        // GET: api/UAM/claim/Employee/find
        [Route("api/UAM/claim/{claim}/find")]
        public IHttpActionResult GetByClaim(string claim = "")
        {
            return Ok(m.UAGetAllByClaim(claim));
        }

        // GET: api/UAM/claims
        [Route("api/UAM/claims")]
        public IHttpActionResult GetAllClaims()
        {
            return Ok(m.UAGetAllClaims());
        }

        // GET: api/UAM/claim/Employee/find
        [Route("api/UAM/claim/{claim}/except")]
        public IHttpActionResult GetByClaimExcept(string claim = "")
        {
            return Ok(m.UAGetAllByClaimExcept(claim));
        }

        // PUT: api/UAM/claim/update
        [Route("api/UAM/claim/update")]
        public IHttpActionResult PutUpdateClaim(MSClaimEdit model)
        {
            // Ensure that an "editedItem" is in the entity body
            if (model == null)
            {
                return BadRequest("Must send an entity body with the request");
            }

            // Ensure that we can use the incoming data
            if (ModelState.IsValid)
            {
                // Attempt to update the item
                m.UAUpdateClaims(model);
                return Ok();
            }
            else
            {
                return BadRequest(ModelState);
            }
        }

        /*
        // POST: api/UAM
        public void Post([FromBody]string value)
        {
        }

        // PUT: api/UAM/5
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE: api/UAM/5
        public void Delete(int id)
        {
        }
        */
    }
}
