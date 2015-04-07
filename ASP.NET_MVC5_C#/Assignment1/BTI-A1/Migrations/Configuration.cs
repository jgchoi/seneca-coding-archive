namespace BTI_A1.Migrations
{
    using BTI_A1.Models;
    using System;
    using System.Data.Entity;
    using System.Data.Entity.Migrations;
    using System.Linq;

    internal sealed class Configuration : DbMigrationsConfiguration<BTI_A1.Models.ApplicationDbContext>
    {
        public Configuration()
        {
            AutomaticMigrationsEnabled = false;
            ContextKey = "BTI_A1.Models.ApplicationDbContext";
        }

        protected override void Seed(BTI_A1.Models.ApplicationDbContext context)
        {
            //  This method will be called after migrating to the latest version.

            //  You can use the DbSet<T>.AddOrUpdate() helper extension method 
            //  to avoid creating duplicate seed data. E.g.
            //
            //    context.People.AddOrUpdate(
            //      p => p.FullName,
            //      new Person { FullName = "Andrew Peters" },
            //      new Person { FullName = "Brice Lambson" },
            //      new Person { FullName = "Rowan Miller" }
            //    );
            //
            //Program Data
            /*
             * context.Programs.AddOrUpdate(
                p => p.Name,
                new Program { Name = "BSD", Code = "BSD", Description = "Description for BSD" },
                new Program { Name = "IFS", Code = "IFS", Description = "Description for IFS" },
                new Program { Name = "CPA", Code = "CPA", Description = "Description for CPA" }
                );
            //Course Data
            context.Courses.AddOrUpdate(
                p => p.Name,
                new Course { Name = "BTP400", Code = "BTP400", Description = "Description for 0" },
                new Course { Name = "BTN415", Code = "BTN415", Description = "Description for 1" },
                new Course { Name = "BTI420", Code = "BTI420", Description = "Description for 2" },
                new Course { Name = "BTS430", Code = "BTS430", Description = "Description for 3" },
                new Course { Name = "BTC440", Code = "BTC440", Description = "Description for 4" }
                );

            //Save Data
            context.SaveChanges();
             * 

            base.Seed(context);

            //Program Data
            context.Programs.Add(new Program { Name = "BSD", Code = "BSD", Description = "Description for BSD" });
            context.Programs.Add(new Program { Name = "IFS", Code = "IFS", Description = "Description for IFS" });
            context.Programs.Add(new Program { Name = "CPA", Code = "CPA", Description = "Description for CPA" });

            //Course Data
            context.Courses.Add(new Course { Name = "BTP400", Code = "BTP400", Description = "Description for 0" });
            context.Courses.Add(new Course { Name = "BTN415", Code = "BTN415", Description = "Description for 1" });
            context.Courses.Add(new Course { Name = "BTI420", Code = "BTI420", Description = "Description for 2" });
            context.Courses.Add(new Course { Name = "BTS430", Code = "BTS430", Description = "Description for 3" });
            context.Courses.Add(new Course { Name = "BTC440", Code = "BTC440", Description = "Description for 4" });

            //Save Data
            context.SaveChanges();
             * 
             * */
        }
    }
}
