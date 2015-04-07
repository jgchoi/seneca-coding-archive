using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// added...
using Notes.Models;
using CsvHelper;
using AutoMapper;
using System.IO;
using Microsoft.AspNet.Identity.Owin;
using System.Security.Claims;

namespace Notes.Controllers
{
    public class Manager
    {
        // Data store
        private ApplicationDbContext ds = new ApplicationDbContext();

        // Security context for the currently-executing request
        // This enables you to reference the User object in this class
        // in a way that's similar to what you can do in a controller
        private ClaimsPrincipal User = HttpContext.Current.User as ClaimsPrincipal;

        // The app's UserManager
        // Must have a reference to this object
        // DO NOT - repeat - DO NOT - do ASP.NET Identity operations directly on the data store
        private ApplicationUserManager _userManager;
        public ApplicationUserManager UserManager
        {
            get
            {
                // Null coalescing operator
                // https://msdn.microsoft.com/en-us/library/ms173224.aspx
                return _userManager ?? HttpContext.Current.GetOwinContext().GetUserManager<ApplicationUserManager>();
            }
            private set
            {
                _userManager = value;
            }
        }

        // Constructor
        public Manager()
        {
            // AutoMapper maps

            Mapper.CreateMap<Models.ApplicationUser, Controllers.ApplicationUserBase>();

            Mapper.CreateMap<Models.OU, Controllers.OUList>();

            Mapper.CreateMap<Models.Employee, Controllers.EmployeeBase>();
            Mapper.CreateMap<Models.Employee, Controllers.EmployeeList>();
            Mapper.CreateMap<Models.Employee, Controllers.EmployeeBaseWithAssociatedData>();
            Mapper.CreateMap<Controllers.EmployeeBase, Controllers.EmployeeDirectReportsForm>();

            Mapper.CreateMap<Models.Note, Controllers.NoteBase>();
            Mapper.CreateMap<Controllers.NoteEdit, Controllers.NoteBase>();
            Mapper.CreateMap<Controllers.NoteAdd, Models.Note>();
            Mapper.CreateMap<Controllers.NoteAdd, Controllers.NoteAddForm>();
            Mapper.CreateMap<Controllers.NoteBase, Controllers.NoteEditForm>();

        }

        // ########################################
        // Service methods

        // Is the current security context user an administrator?
        private bool IsAdministrator()
        {
            return this.User.HasClaim(ClaimTypes.Role, "Administrator") ? true : false;
        }

        // Is the current security context user a manager?
        private bool IsManager()
        {
            return this.User.HasClaim(ClaimTypes.Role, "Manager") ? true : false;
        }

        // Used during 'create new account'
        public bool IsNewUserAnEmployee(string name)
        {
            if (string.IsNullOrEmpty(name))
            {
                return false;
            }
            else
            {
                var fetchedObject = ds.Employees.SingleOrDefault(e => e.IdentityUserId == name);

                return (fetchedObject == null) ? false : true;
            }
        }

        public bool IsUserAManager(string username)
        {
            // Fetch the user
            var user = UserManager.FindByNameAsync(username).Result;
            if (user == null) { return false; }

            // Look for the manager claim
            var managerClaim = user.Claims
                .SingleOrDefault(c => c.ClaimType == ClaimTypes.Role & c.ClaimValue == "Manager");

            return managerClaim == null ? false : true;
        }

        // The following method returns an Employee Id or null
        public int? GetEmployeeIdForUserName(string userName)
        {
            var user = UserManager.FindByNameAsync(userName).Result;

            // Non-matching user name
            if (user == null) { return null; }

            // Test whether the user is the same as the security context user
            if (user.UserName == User.Identity.Name)
            {
                // Fetch the employee by user name
                var employee = ds.Employees.SingleOrDefault(e => e.IdentityUserId == user.UserName);

                return employee == null ? null : (int?)employee.Id;
            }
            else
            {
                return null;
            }
        }

        // Used during 'create new account'
        public bool ConfigureUserWithOU(string name, string selectedOU)
        {
            if (string.IsNullOrEmpty(name))
            {
                return false;
            }
            else
            {
                var fetchedObject = ds.Employees.SingleOrDefault(e => e.IdentityUserId == name);

                fetchedObject.OU = selectedOU;
                ds.SaveChanges();

                return fetchedObject == null ? false : true;
            }
        }

        public void LoadOUs()
        {
            if (IsAdministrator() & ds.OUs.Count() == 0)
            {
                // Add some OUs...
                ds.OUs.Add(new OU { OUName = "Executive Office" });
                ds.OUs.Add(new OU { OUName = "Electrical" });
                ds.OUs.Add(new OU { OUName = "Editorial" });
                ds.OUs.Add(new OU { OUName = "Research & Development" });
                ds.OUs.Add(new OU { OUName = "Talent" });
                ds.OUs.Add(new OU { OUName = "Human Resources" });
                ds.OUs.Add(new OU { OUName = "Production" });
                ds.OUs.Add(new OU { OUName = "Creative" });

                ds.SaveChanges();
            }
        }

        public void LoadEmployeesFromCSV()
        {
            // Test if there's data first, and if yes, return the existing data
            // In other words, do NOT load the data again

            if (IsAdministrator() & ds.Employees.Count() == 0)
            {
                // File system path to the data file (in this project's App_Data folder)
                string path = HttpContext.Current.Server.MapPath("~/App_Data/Employees.csv");

                // Create a stream reader object, to read from the file system
                StreamReader sr = File.OpenText(path);

                // Create the CsvHelper object
                var csv = new CsvReader(sr);

                // Create the AutoMapper mapping
                Mapper.CreateMap<Controllers.EmployeeAdd, Models.Employee>();

                // Go through the data file
                while (csv.Read())
                {
                    // Read one line in the source file 
                    EmployeeAdd newItem = csv.GetRecord<EmployeeAdd>();

                    // Create a new employee object
                    Employee addedItem = Mapper.Map<Employee>(newItem);

                    // Add the new object to the data store
                    ds.Employees.Add(addedItem);
                }

                ds.SaveChanges();

                // Clean up
                sr.Close();
                sr = null;
            }
        }

        // Not used in this app, but you could use it if you wish
        public void DeleteAllNotes()
        {
            if (IsAdministrator() & ds.Notes.Count() > 0)
            {
                // Clunky, but this is the most efficient way
                ds.Database.ExecuteSqlCommand("delete from notes");
            }
        }

        // Not used in this app, but you could use it if you wish
        public void DeleteAllEmployees()
        {
            if (IsAdministrator() & ds.Employees.Count() > 0)
            {
                // Clunky, but this is the most efficient way
                ds.Database.ExecuteSqlCommand("delete from employees");
            }
        }

        // Not used in this app, but you could use it if you wish
        public void DeleteAllOUs()
        {
            if (IsAdministrator() & ds.OUs.Count() > 0)
            {
                // Clunky, but this is the most efficient way
                ds.Database.ExecuteSqlCommand("delete from ous");
            }
        }

        // ########################################
        // Data-handling methods

        // ########################################
        // Users

        // Returns a collection of ASP.NET Identity users
        public IEnumerable<ApplicationUserBase> GetAllUsers()
        {
            var allUsers = Mapper.Map<IEnumerable<ApplicationUserBase>>(UserManager.Users.OrderBy(u => u.LastName).ThenBy(u => u.FirstName));

            // Go through the collection, and look for the 'Manager' role claim
            foreach (var user in allUsers)
            {
                var managerClaim = user.Claims.SingleOrDefault
                    (c => c.ClaimType == ClaimTypes.Role & c.ClaimValue == "Manager");

                user.IsManager = managerClaim == null ? "no" : "YES";
            }

            // Return
            return allUsers;
        }

        // Returns one ASP.NET Identity user, using a user name lookup
        public ApplicationUserBase GetUserByUserName(string userName)
        {
            var user = UserManager.FindByNameAsync(userName).Result;

            return user == null ? null : Mapper.Map<ApplicationUserBase>(user);
        }

        // Returns a collection of ASP.NET Identity users, 
        // which do NOT have the 'manager' role claim
        public IEnumerable<ApplicationUserBase> GetAllNonManagerUsers()
        {
            // Two-step process... remove administrator(s), then managers

            // First, get all non-admin users
            // Notice the use of ! to reverse the logic of the Where method
            var nonAdmins = UserManager.Users
                .Where(u => !u.Claims
                    .Any(c => c.ClaimType == ClaimTypes.Role & c.ClaimValue == "Administrator"));

            // Then, get all non-manager users
            // Notice the use of ! to reverse the logic of the Where method
            var nonManagers = nonAdmins
                .Where(u => !u.Claims
                    .Any(c => c.ClaimType == ClaimTypes.Role && c.ClaimValue == "Manager"));

            return Mapper.Map<IEnumerable<ApplicationUserBase>>(nonManagers);
        }

        public bool ConfigureUserAsManager(string username)
        {
            // Fetch the user
            var user = UserManager.FindByNameAsync(username).Result;
            if (user == null) { return false; }

            // Maybe you should add another check to ensure that the user does NOT
            // have the 'manager' role claim

            // Add the 'Manager' role claim
            var result = UserManager.AddClaimAsync(user.Id, new Claim(ClaimTypes.Role, "Manager")).Result;

            return result.Succeeded ? true : false;
        }

        // ########################################
        // OUs

        public IEnumerable<OUList> GetAllOUs()
        {
            var fetchedObjects = ds.OUs.OrderBy(e => e.OUName);

            return Mapper.Map<IEnumerable<OUList>>(fetchedObjects);
        }

        // ########################################
        // Employees

        public IEnumerable<EmployeeBase> GetAllEmployees()
        {
            var fetchedObjects = ds.Employees.OrderBy(e => e.FamilyName).ThenBy(e => e.GivenNames);

            return Mapper.Map<IEnumerable<EmployeeBase>>(fetchedObjects);
        }

        public IEnumerable<EmployeeBase> GetAllEmployeesNoManager()
        {
            // Would like to use an expression in the Where() method
            // However, it will not work, and will generate an error...
            // LINQ to Entities does not recognize the method 'GetValueOrDefault'
            // The problem is that we're attempting to send an expression
            // as a SQL statement to the store

            // Therefore, we have to bring the collection into local memory
            // Then we can use the expression

            // Fetch all the objects
            var fetchedObjects = ds.Employees.AsEnumerable();

            // Filter the collection with an expression
            var filteredObjects = fetchedObjects
                .Where(e => e.ManagerId.GetValueOrDefault() == 0)
                .OrderBy(e => e.FamilyName).ThenBy(e => e.GivenNames);

            // Return the results
            return Mapper.Map<IEnumerable<EmployeeBase>>(filteredObjects);
        }

        public EmployeeBase GetEmployeeById(int id)
        {
            var fetchedObject = ds.Employees.Find(id);

            // Test whether the user is the same as the security context user
            if (fetchedObject.IdentityUserId == User.Identity.Name)
            {
                return Mapper.Map<EmployeeBase>(fetchedObject);
            }
            else
            {
                return null;
            }
        }

        public EmployeeBaseWithAssociatedData GetEmployeeByIdWithAssociatedData(int id)
        {
            // Fetch the collection
            // Include the associated objects and collections

            // Test whether the user is the same as the security context user
            // If yes, can return the object
            var fetchedObject = ds.Employees.Include("Manager").Include("DirectReports").Include("Notes").SingleOrDefault(e => e.Id == id);
            // Test whether the user is the same as the security context user
            if (fetchedObject == null)
            {
                return null;
            }
            else if (fetchedObject.IdentityUserId == User.Identity.Name)
            {
                return Mapper.Map<EmployeeBaseWithAssociatedData>(fetchedObject);
            }
            else
            {
                return null;
            }
            return null;
        }

        public NoteBase GetNoteForAuthenticatedEmployee(int id)
        {
            // Fetch the requested object
            // Must include the associated Employee object,
            var fetchedObject = ds.Notes.Include("Employee").SingleOrDefault(i => i.Id == id);
            // because you will need that next...

            // Test whether the user is the same as the security context user
            if (User.Identity.Name == fetchedObject.Employee.IdentityUserId)
            {
                //if yes return fetched object.
                return Mapper.Map<NoteBase>(fetchedObject);
            }
            else
                return null;


        }

        public NoteBase AddNoteForAuthenticatedEmployee(NoteAdd newItem)
        {
            // Validate the incoming item, by fetching the employee object
            Employee employee = ds.Employees.Find(newItem.EmployeeId);
            if (employee == null)
            {
                return null;
            }
            else if (employee.IdentityUserId != User.Identity.Name)
            {// Test whether the user is the same as the security context user
                return null;
            }
            else
            {// If yes, can add the new note object, and then return it
                Note addedItem = Mapper.Map<Note>(newItem);

                addedItem.Timestamp = DateTime.Now;
                addedItem.Employee = employee;

                //add to db
                addedItem = ds.Notes.Add(addedItem);
                employee.Notes.Add(addedItem);
                ds.SaveChanges();

                var returnItem = Mapper.Map<NoteBase>(addedItem);
                returnItem.EmployeeId = newItem.EmployeeId;
                ds.SaveChanges();
                return Mapper.Map<NoteBase>(returnItem);
            }
        }

        public IEnumerable<EmployeeList> ConfigureDirectReports(EmployeeDirectReports newItem)
        {
            // Validate the incoming item, by fetching the employee ('manager') object
            var manager = ds.Employees.Find(newItem.Id);
            if (manager == null)
                return null;

            // Test whether the user is the same as the security context user
            if (manager.IdentityUserId != User.Identity.Name)
                return null;

            // If yes...
            var addedCollection = new List<EmployeeList>();
            // Process the items in the incoming collection
            foreach (var item in newItem.EmployeeIds) // Each needs to lookup the affected employee
            {
                var emp = ds.Employees.Find(item);
                // Then setting the 'manager' properties (both of them)
                manager.DirectReports.Add(emp);
                // And save
                // As this work happens, it's useful to accumulate EmployeeList objects

                addedCollection.Add(Mapper.Map<EmployeeList>(emp));
                ds.SaveChanges();
            }
            // so that you can return them as a collection, which could be useful

            return addedCollection;
        }

        public NoteBase UpdateNoteForAuthenticatedEmployee(NoteEdit newItem)
        {
            // Validate the incoming item, by fetching the employee object
            Employee employee = ds.Employees.Find(newItem.EmployeeId);
            if (employee == null)
            {
                return null;
            }
            else if (employee.IdentityUserId != User.Identity.Name)
            {// Test whether the user is the same as the security context user
                return null;
            }
            else
            {// If yes, can add the new note object, and then return it                

                //update note
                ds.Entry(ds.Notes.Find(newItem.NoteId)).CurrentValues.SetValues(Mapper.Map<NoteAdd>(newItem));

                var returnItem = Mapper.Map<NoteBase>(newItem);
                returnItem.EmployeeId = newItem.EmployeeId;
                ds.SaveChanges();
                return Mapper.Map<NoteBase>(returnItem);
            }
        }

        public EmployeeBase deleteNoteById(int id)
        {
            //load note object
            var deletedItem = ds.Notes.Include("Employee").SingleOrDefault(e => e.Id == id);

            //Check note object
            if (deletedItem == null)
                return null;

            //check user's name and note's owner
            if (User.Identity.Name != deletedItem.Employee.IdentityUserId)
                return null;

            //assign employee object ro local variable
            var owner = deletedItem.Employee;

            //remove note from the employee
            owner.Notes.Remove(deletedItem);

            //delete note
            ds.Notes.Remove(deletedItem);

            //save change
            ds.SaveChanges();

            //return employee
            return Mapper.Map<EmployeeBase>(owner);
        }
    }

}