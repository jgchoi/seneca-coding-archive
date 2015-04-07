using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace BTI_A1.Models
{

    public class StoreInitializer : CreateDatabaseIfNotExists<ApplicationDbContext>
    {
        protected override void Seed(ApplicationDbContext context)
        {
            base.Seed(context);

            //Program Data
            context.Programs.Add(new Program { Name = "BSD", Code="BSD",Description="Description for BSD" });
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

        }
    }

}