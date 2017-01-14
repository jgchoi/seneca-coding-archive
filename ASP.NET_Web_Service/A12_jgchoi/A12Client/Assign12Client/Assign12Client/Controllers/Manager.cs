using Assign12Client.SSOS;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Threading.Tasks;
using System.Web;

namespace Assign12Client.Controllers
{
    public class Manager
    {
        SubjectOutlineServicePortTypeClient ss = new SubjectOutlineServicePortTypeClient();

        // ############################################################
        // HTTP request factory

        // This is a factory, which creates an HttpClient object for a web service request...
        // Configured with the base URI, and headers (accept and authorization)

        private HttpClient CreateRequest(string acceptValue = "application/json")
        {
            var request = new HttpClient();

            // Could also fetch the base address string from the app's global configuration
            // Base URI of the web service we are interacting with
            request.BaseAddress = new Uri("https://ict.senecacollege.ca/api/courses/");

            // Accept header configuration
            request.DefaultRequestHeaders.Accept.Clear();
            request.DefaultRequestHeaders.Accept
                .Add(new System.Net.Http.Headers.MediaTypeWithQualityHeaderValue(acceptValue));

            // Attempt to get the token from session state memory
            // Info: https://msdn.microsoft.com/en-us/library/system.web.httpcontext.session(v=vs.110).aspx

            var token = HttpContext.Current.Session["token"] as string;

            if (string.IsNullOrEmpty(token)) { token = "empty"; }

            // Authorization header configuration
            request.DefaultRequestHeaders.Authorization =
                new System.Net.Http.Headers.AuthenticationHeaderValue
                ("Bearer", token);

            return request;
        }


        // ############################################################
        // Get access token

        // LoginItems is a resource model class that holds the user name and password

        // TokenResponse is a resource model class that matches the shape of the response
        // from the IA Server token endpoint

       

        // ############################################################
        // Use cases

        //public IEnumerable<EmployeeBase> EmployeeGetAll()
        //{
        //    // Create a request
        //    using (var request = CreateRequest())
        //    {
        //        // Send the request... make it complete by adding the Result property
        //        var response = request.GetAsync("employees").Result;

        //        if (response.IsSuccessStatusCode)
        //        {
        //            // Extract the data from the response, return
        //            return response.Content.ReadAsAsync<IEnumerable<EmployeeBase>>().Result;
        //        }
        //        else
        //        {
        //            // Return an empty collection
        //            return new List<EmployeeBase>();
        //        }
        //    }
        //}

        public async Task<IEnumerable<CourseBase>> GetAllCourses()
        {
            using (HttpClient request = CreateRequest())
            {
                // Send the request
                var response = await request.GetAsync("bsd");

                if (response.IsSuccessStatusCode)
                {
                    // Read the response data, and return it
                    return (await response.Content.ReadAsAsync<IEnumerable<CourseBase>>());
                }
                else
                {
                    // For this simple app, return empty list
                    return new List<CourseBase>();
                }
            }
        }

        public SSOS.SubjectOutline SubjectOutlineByCode(string courseCode)
        {
            try
            {
                // Call the web service method
                var fetchedObject = ss.getOutline(courseCode, "20163", "SICT", true);
                if(fetchedObject == null)
                    fetchedObject = ss.getOutline(courseCode, "20171", "SICT", true);
                if (fetchedObject == null)
                    fetchedObject = ss.getOutline(courseCode, "20172", "SICT", true);

                if (fetchedObject == null)
                    fetchedObject = ss.getOutline(courseCode, "20151", "SICT", true);

                return (fetchedObject == null) ? null : fetchedObject;
            }
            catch (System.Exception)
            {

                throw;
            }
           
        }

    }
}