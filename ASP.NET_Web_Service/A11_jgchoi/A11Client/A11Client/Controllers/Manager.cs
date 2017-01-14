using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Threading.Tasks;
using System.Web;

namespace A11Client.Controllers
{
    public class Manager
    {
        // ############################################################
        // HTTP request factory

        // This is a factory, which creates an HttpClient object for a web service request...
        // Configured with the base URI, and headers (accept and authorization)

        private HttpClient CreateRequest(string acceptValue = "application/json")
        {
            var request = new HttpClient();

            // Could also fetch the base address string from the app's global configuration
            // Base URI of the web service we are interacting with
            request.BaseAddress = new Uri("http://localhost:2548/api/");

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

        public async Task<bool> GetAccessToken(LoginItems loginItems)
        {
            // Continue?
            if (loginItems == null) { return false; }

            // Clean the incoming data
            // Packaging alternatives... dictionary or list of key-value pairs

            // Create a package for the request - dictionary
            var rd = new Dictionary<string, string>();
            rd.Add("grant_type", "password");
            // etc.

            // Create a package for the request - list of key-value pairs
            var requestData = new List<KeyValuePair<string, string>>();
            requestData.Add(new KeyValuePair<string, string>("grant_type", "password"));
            requestData.Add(new KeyValuePair<string, string>("password", loginItems.password));
            requestData.Add(new KeyValuePair<string, string>("username", loginItems.username));
            // etc.

            // Create an HttpContent object
            var content = new FormUrlEncodedContent(requestData);

            // Create a request
            using (var request = CreateRequest())
            {
                // Send the request... POST, to token endpoint, with the form URL encoded content
                // Make it complete by adding the Result property
                var response = request.PostAsync("http://localhost:2548/token", content).Result;

                if (response.IsSuccessStatusCode)
                {
                    // Extract the token from the response
                    var tokenResponse = await response.Content.ReadAsAsync<TokenResponse>();

                    // Save the token in session state
                    HttpContext.Current.Session["token"] = tokenResponse.access_token;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }

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

        public async Task<IEnumerable<AppClaimBase>> AppClaimGetAll()
        {
            using (HttpClient request = CreateRequest())
            {
                // Send the request
                var response = await request.GetAsync("AppClaims");

                if (response.IsSuccessStatusCode)
                {
                    // Read the response data, and return it
                    return (await response.Content.ReadAsAsync<IEnumerable<AppClaimBase>>());
                }
                else
                {
                    // For this simple app, return empty list
                    return new List<AppClaimBase>();
                }
            }
        }

        public async Task<IEnumerable<MSUserAccountBase>> UserGetAll()
        {
            using (HttpClient request = CreateRequest())
            {
                // Send the request
                var response = await request.GetAsync("UAM");

                if (response.IsSuccessStatusCode)
                {
                    // Read the response data, and return it
                    return (await response.Content.ReadAsAsync<IEnumerable<MSUserAccountBase>>());
                }
                else
                {
                    // For this simple app, return empty list
                    return new List<MSUserAccountBase>();
                }
            }
        }

    }
}