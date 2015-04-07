using System.Data.Entity;
using System.Security.Claims;
using System.Threading.Tasks;
using Microsoft.AspNet.Identity;
using Microsoft.AspNet.Identity.EntityFramework;

namespace BTI_A1.Models
{
    // You can add profile data for the user by adding more properties to your ApplicationUser class, please visit http://go.microsoft.com/fwlink/?LinkID=317594 to learn more.
    public class ApplicationUser : IdentityUser
    {
        //Added properties
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public async Task<ClaimsIdentity> GenerateUserIdentityAsync(UserManager<ApplicationUser> manager)
        {
            // Note the authenticationType must match the one defined in CookieAuthenticationOptions.AuthenticationType
            var userIdentity = await manager.CreateIdentityAsync(this, DefaultAuthenticationTypes.ApplicationCookie);
            // Add custom user claims here
            return userIdentity;
        }
    }

    public class ApplicationDbContext : IdentityDbContext<ApplicationUser>
    {
        public ApplicationDbContext()
            : base("DataContext", throwIfV1Schema: false)
        {
        }

        //Data Table
        public DbSet<Program> Programs { get; set;}
        public DbSet<Course> Courses { get; set; }
        public DbSet<Suggestion> Suggestions { get; set; }
        public DbSet<FollowUp> FollowUps { get; set; }



        public static ApplicationDbContext Create()
        {
            return new ApplicationDbContext();
        }
    }
}