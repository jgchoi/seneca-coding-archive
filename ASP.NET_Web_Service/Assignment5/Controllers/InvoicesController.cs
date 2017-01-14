using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace Assignment5.Controllers
{
    public class InvoicesController : ApiController
    {

        private Manager m = new Manager();

        /// <summary>
        ///  Get all invocies
        /// </summary>
        /// <returns>Invoices with link information and template about add invoice</returns>
        // GET: api/Invoices
        public IHttpActionResult Get()
        {
            // Get all
            var c = m.InvoiceGetAll();

            // Create a hypermedia representation
            InvoicesLinked result = new InvoicesLinked(Mapper.Map<IEnumerable<InvoiceWithLink>>(c));

            return Ok(result);
        }
    }
}
