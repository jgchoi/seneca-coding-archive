using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment8.Models;
using Microsoft.AspNet.Identity.Owin;
using System.Security.Claims;
using Microsoft.AspNet.Identity.EntityFramework;
using Microsoft.AspNet.Identity;

namespace Assignment8.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private ApplicationDbContext ds = new ApplicationDbContext();

        public Manager()
        {
            // If necessary, add constructor code here

            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            ds.Configuration.LazyLoadingEnabled = false;
        }

        // Add methods below
        // Controllers will call these methods
        // Ensure that the methods accept and deliver ONLY view model objects and collections
        // The collection return type is almost always IEnumerable<T>

        // Suggested naming convention: Entity + task/action
        // For example:
        // ProductGetAll()
        // ProductGetById()
        // ProductAdd()
        // ProductEdit()
        // ProductDelete()




        // ############################################################
        // AppClaim

        // AppClaimGetAll
        public IEnumerable<AppClaimBase> AppClaimGetAll()
        {
            var c = ds.AppClaims.OrderBy(a => a.ClaimType).ThenBy(a => a.ClaimValue);

            return Mapper.Map<IEnumerable<AppClaimBase>>(c);
        }

        // AppClaimGetAllActive
        public IEnumerable<AppClaimBase> AppClaimGetAllActive()
        {
            var c = ds.AppClaims
                .Where(a => a.DateRetired == null)
                .OrderBy(a => a.ClaimType).ThenBy(a => a.ClaimValue);

            return Mapper.Map<IEnumerable<AppClaimBase>>(c);
        }

        // AppClaimGetById
        public AppClaimBase AppClaimGetById(int id)
        {
            // Attempt to fetch the object
            var o = ds.AppClaims.Find(id);

            return (o == null) ? null : Mapper.Map<AppClaimBase>(o);
        }

        // AppClaimGetByMatch
        public AppClaimBase AppClaimGetByMatch(string claimType = "", string claimValue = "")
        {
            // Clean the incoming data
            claimType = claimType.Trim().ToLower();
            claimValue = claimValue.Trim().ToLower();

            // Attempt to fetch the object
            var o = ds.AppClaims
                .SingleOrDefault(a => a.ClaimType.ToLower() == claimType && a.ClaimValue.ToLower() == claimValue);

            return (o == null) ? null : Mapper.Map<AppClaimBase>(o);
        }

        // AppClaimGetAllRoles
        public IEnumerable<AppClaimBase> AppClaimGetAllRoles()
        {
            var c = ds.AppClaims
                .Where(a => a.DateRetired == null)
                .Where(a => a.ClaimType.ToLower() == "role")
                .OrderBy(a => a.ClaimType).ThenBy(a => a.ClaimValue);

            return Mapper.Map<IEnumerable<AppClaimBase>>(c);
        }

        // AppClaimGetByType case insensitive, active
        public IEnumerable<AppClaimBase> AppClaimGetByType(string claimType = "")
        {
            throw new NotImplementedException();
        }

        // AppClaimGetByValue case insensitive, active
        public IEnumerable<AppClaimBase> AppClaimGetByValue(string claimValue = "")
        {
            throw new NotImplementedException();
        }

        // AppClaimAdd
        public AppClaimBase AppClaimAdd(AppClaimAdd newItem)
        {
            // Maybe check for a retired match and resurrect it
            // Also check for existing match - keep them unique

            // Initial version of the method, without the fixes above...
            // Attempt to add the object
            var addedItem = ds.AppClaims.Add(Mapper.Map<AppClaim>(newItem));

            // Help configure a role claim with the official URI
            if (addedItem.ClaimType.ToLower() == "role")
            {
                addedItem.ClaimTypeUri = "http://schemas.microsoft.com/ws/2008/06/identity/claims/role";
            }

            ds.SaveChanges();

            // Return the result
            return (addedItem == null) ? null : Mapper.Map<AppClaimBase>(addedItem);
        }

        // AppClaimEdit description, types and values, active
        public AppClaimBase AppClaimEdit(AppClaimEdit editedItem)
        {
            // Ensure that we can continue
            if (editedItem == null) { return null; }

            // Attempt to fetch the object
            var storedItem = ds.AppClaims.Find(editedItem.Id);

            if (storedItem == null)
            {
                return null;
            }
            else
            {

                ds.Entry(storedItem).CurrentValues.SetValues(editedItem);
                // The SetValues() method ignores missing properties and navigation properties
                ds.SaveChanges();

                return Mapper.Map<AppClaimBase>(storedItem);
            }
        }

        // AppClaimDelete which doesn't really delete, could be a command
        public bool AppClaimDelete(int id)
        {


            // Attempt to fetch the object
            var storedItem = ds.AppClaims.Find(id);

            if (storedItem == null)
            {
                return false;
            }
            else
            {
                storedItem.DateRetired = DateTime.Today;  
                ds.SaveChanges();
                return true;
            }
        }

        // ############################################################
        // User account management

        // All user accounts
        public IEnumerable<MSUserAccountBase> UAGetAll()
        {
            // Get a reference to the application's user manager
            var userManager = HttpContext.Current.GetOwinContext().GetUserManager<ApplicationUserManager>();

            // Return the entire user account collection, mapped
            return Mapper.Map<IEnumerable<MSUserAccountBase>>(userManager.Users);
        }

        // One user account, by its 32-hex-character identifier
        public MSUserAccountWithClaims UAGetOneById(string id = "")
        {
            // Get a reference to the application's user manager
            var userManager = HttpContext.Current.GetOwinContext().GetUserManager<ApplicationUserManager>();

            // Attempt to locate the object
            var o = userManager.FindByIdAsync(id).Result;

            return (o == null) ? null : Mapper.Map<MSUserAccountWithClaims>(o);
        }

        // One user account, by its email address
        public MSUserAccountWithClaims UAGetOneByEmail(string email = "")
        {
            // Get a reference to the application's user manager
            var userManager = HttpContext.Current.GetOwinContext().GetUserManager<ApplicationUserManager>();

            // Attempt to locate the object
            var o = userManager.FindByEmailAsync(email).Result;

            return (o == null) ? null : Mapper.Map<MSUserAccountWithClaims>(o);
        }

        // Collection of zero or more user accounts that match surname (case-insensitive)
        public IEnumerable<MSUserAccountBase> UAGetAllBySurname(string surname = "")
        {
            // Get a reference to the application's user manager
            var userManager = HttpContext.Current.GetOwinContext().GetUserManager<ApplicationUserManager>();

            // Fetch the user accounts into an in-memory object graph so we can query it
            // without going back to the data store again and again
            var allUsers = userManager.Users.ToList();

            // Now, look for users where the surname claim matches the incoming value
            var matchingUsers = allUsers.Where
                (u => u.Claims.Any(c => c.ClaimType == ClaimTypes.Surname && c.ClaimValue.ToLower() == surname.Trim().ToLower()));

            return Mapper.Map<IEnumerable<MSUserAccountBase>>(matchingUsers);
        }

        // Collection of zero or more user accounts that match claim (case-insensitive)
        public IEnumerable<MSUserAccountBase> UAGetAllByClaim(string claim = "")
        {
            // Get a reference to the application's user manager
            var userManager = HttpContext.Current.GetOwinContext().GetUserManager<ApplicationUserManager>();

            // Split Claims

            string[] r = claim.Split(new char[] { '=' });
            if (r.Length == 2)
            {
                var claimType = r[0].Trim();
                var claimValue = r[1].Trim();

                // Fetch the user accounts into an in-memory object graph so we can query it
            // without going back to the data store again and again
            var allUsers = userManager.Users.ToList();

            // Now, look for users where the surname claim matches the incoming value
            var matchingUsers = allUsers.Where
                (u => u.Claims.Any(c => c.ClaimType == claimType && c.ClaimValue.ToLower() == claimValue.Trim().ToLower()));

            return Mapper.Map<IEnumerable<MSUserAccountBase>>(matchingUsers);
            }
            else
            {
                return null;
            }    
        }

        // Collection of zero or more user accounts that match claim (case-insensitive)
        public IEnumerable<MSClaimList> UAGetAllClaims()
        {
            // Get a reference to the application's user manager
            var userManager = HttpContext.Current.GetOwinContext().GetUserManager<ApplicationUserManager>();
            IEnumerable<IdentityUserClaim> allClaims = new List<IdentityUserClaim>();
            foreach (var user in userManager.Users.ToList())
            {
                var userClaims = user.Claims;
                allClaims = allClaims.Union(userClaims, new ClaimComparer()).ToList();
                allClaims.OrderBy(x => x.ClaimType).ThenBy(x => x.ClaimType);
            }
            return Mapper.Map<IEnumerable<MSClaimList>>(allClaims);
        }

        public void UAUpdateClaims(MSClaimEdit model)
        {
            var userManager = HttpContext.Current.GetOwinContext().GetUserManager<ApplicationUserManager>();

            // Clean / tidy / trim the incoming type and value strings
            var claimType = model.ClaimType.Trim();
            var claimValue = model.ClaimValue.Trim();

            // Validate the requested claim against the master list of allowed claims 
            if (AppClaimGetByMatch(claimType, claimValue) == null) { return; }
            
            foreach (var email in model.EmailAddresses)
            {
                var trimedEmail = email.Trim();
                // Using the user manager object, attempt to find the user account by its email address
                var o = userManager.FindByEmailAsync(email).Result;

                // If found, check whether it already has the requested claim
                if(o.Claims.Where(c => c.ClaimType == claimType && c.ClaimValue.ToLower() == claimValue.Trim().ToLower()).Count() == 0)
                {
                    IdentityResult result = userManager.AddClaim(o.Id, new Claim(claimType, claimValue));
                }

            }

        }

        // Collection of zero or more user accounts that match claim (case-insensitive)
        public IEnumerable<MSUserAccountBase> UAGetAllByClaimExcept(string claim = "")
        {
            // Get a reference to the application's user manager
            var userManager = HttpContext.Current.GetOwinContext().GetUserManager<ApplicationUserManager>();

            // Split Claims

            string[] r = claim.Split(new char[] { '=' });
            if (r.Length == 2)
            {
                var claimType = r[0].Trim();
                var claimValue = r[1].Trim();

                // Fetch the user accounts into an in-memory object graph so we can query it
                // without going back to the data store again and again
                var allUsers = userManager.Users.ToList();

                // Now, look for users where the surname claim matches the incoming value
                var matchingUsers = allUsers.Where
                    (u => u.Claims.Any(c => c.ClaimType == claimType && c.ClaimValue.ToLower() == claimValue.Trim().ToLower()));

                var remindingUsers = userManager.Users.ToList();

                foreach (var user in matchingUsers)
                {
                    remindingUsers.Remove(user);
                }
                return Mapper.Map<IEnumerable<MSUserAccountBase>>(remindingUsers);
            }
            else
            {
                return null;
            }
        }
        

    }
}