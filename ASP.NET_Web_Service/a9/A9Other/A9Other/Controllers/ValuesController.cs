using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace A9Other.Controllers
{
    [Authorize]
    public class ValuesController : ApiController
    {
        // GET api/values
        [Authorize(Roles = "customer")]
        public IEnumerable<string> Get()
        {
            return new string[] { "value1", "value2" };
        }

        // GET api/values/5
        [Authorize(Roles = "employee")]
        [AuthorizeClaim(ClaimType = "ou", ClaimValue = "london")]
        public string Get(int id)
        {
            return "get";
        }

        // POST api/values
        [AuthorizeClaim(ClaimType = "task", ClaimValue = "editMusic")]
        public string Post([FromBody]string value)
        {
            return "Post";
        }

        [AuthorizeClaim(ClaimType = "task", ClaimValue = "addMusic")]
        // PUT api/values/5
        public string Put(int id, [FromBody]string value)
        {
            return "Put";
        }

        [Authorize(Roles = "employee")]
        [AuthorizeClaim(ClaimType = "ou", ClaimValue = "service")]
        // DELETE api/values/5
        public void Delete(int id)
        {
        }
    }
}
