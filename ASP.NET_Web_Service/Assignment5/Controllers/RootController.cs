using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace Assignment5.Controllers
{
    public class RootController : ApiController
    {
        /// <summary>
        /// Returns all available api calls
        /// </summary>
        /// <returns>All api calls</returns>
        // GET: api/Root
        public IHttpActionResult Get()
        {
            // Create a collection of Link objects

            List<Link> links = new List<Link>();
            links.Add(new Link() { Rel = "collection", Href = "/api/customers", Method = "GET,POST" });
            links.Add(new Link() { Rel = "item", Href = "/api/customers/{id}", Method = "GET,PUT" });
            links.Add(new Link() { Rel = "item", Href = "/api/employees/{id}/setsupportrep", Method = "PUT" });
            links.Add(new Link() { Rel = "collection", Href = "/api/invoices", Method = "GET" });         

            // Create and configure a dictionary to hold the collection
            // We need to return a simple object, so a Dictionary<TKey, TValue> is ideal

            Dictionary<string, List<Link>> linkList = new Dictionary<string, List<Link>>();
            linkList.Add("Links", links);

            return Ok(linkList);
        }
    }
}
