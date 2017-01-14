using Microsoft.AspNet.Identity.Owin;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Security.Claims;
using System.Web.Http;

namespace Assignment8.Controllers
{
    public class A8TestController : ApiController
    {
        public IEnumerable<string> Get()
        {
            // Container for user and claims info
            List<string> allClaims = new List<string>();

            // Is this request authenticated?
            allClaims.Add("Authenticated = " + (User.Identity.IsAuthenticated ? "Yes" : "No"));
            if (User.Identity.IsAuthenticated)
            {
                // Cast the generic principal to a claims-carrying identity
                var identity = User.Identity as ClaimsIdentity;
                // Extract only the claims
                var claims = identity.Claims
                    .Select(c => new { Type = c.Type, Value = c.Value })
                    .AsEnumerable();
                foreach (var claim in claims)
                {
                    // Create a readable string
                    allClaims.Add(claim.Type + " = " + claim.Value);
                }
            }

            return allClaims;
        }

        // GET: Test/UserList
        // Attention 33 - This will fetch the list of registered users
        [Route("api/test/userlist")]
        public IHttpActionResult GetUserList()
        {
            // Container to hold the user names
            var userList = new List<string>();

            // Get a reference to the application's user manager
            var userManager = Request.GetOwinContext()
                .GetUserManager<ApplicationUserManager>();

            // Go through the users, and extract their names
            foreach (var user in userManager.Users)
            {
                userList.Add(user.UserName);
            }

            return Ok(userList);
        }

        // Attention 34 - These methods enable testing of specific role claims - read carefully

        // The remaining tests will return...
        // if successfully authorized - a simple string message
        // if authorization fails - HTTP 401

        // Note the URI pattern for these tests
        // They aren't 'real world' or 'best practice', but they're simple

        // Any account
        [Authorize]
        [Route("api/test/anyaccount")]
        public IEnumerable<string> GetAnyAccount()
        {
            return new string[] { "any account", "works correctly" };
        }

        // Role "User"
        [Authorize(Roles = "User")]
        [Route("api/test/role/user")]
        public IEnumerable<string> GetRoleUser()
        {
            return new string[] { "role user", "works correctly" };
        }

        [AuthorizeClaim(ClaimType = "OU", ClaimValue = "Publisher")]
        [Route("api/test/claim/publisher")]
        public IEnumerable<string> GetPublisher()
        {
            return new string[] { "claim OU publisher", "works correctly" };
        }

        [AuthorizeClaim(ClaimType = "OU", ClaimValue = "Manager")]
        [Route("api/test/claim/Manager")]
        public IEnumerable<string> GetManager()
        {
            return new string[] { "claim OU Manager", "works correctly" };
        }

        [AuthorizeClaim(ClaimType = "Task", ClaimValue = "AlbumCreator")]
        [Route("api/test/claim/AlbumCreator")]
        public IEnumerable<string> GetAlbumCreator()
        {
            return new string[] { "claim Task AlbumCreator", "works correctly" };
        }
       

    }
}
