using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace Assignment6.Controllers
{
    public class TracksController : ApiController
    {
        Manager m = new Manager();

        /// <summary>
        /// This method returns all track information available with Album name, and Artist Name
        /// </summary>
        /// <returns>TrackBase</returns>
        // GET: api/Tracks
        public IHttpActionResult Get()
        {
            return Ok(m.TrackGetAll());
        }
    }
}
