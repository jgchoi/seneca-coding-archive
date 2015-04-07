using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using System.Data.Entity;

namespace Lab4.Models
{
    public class StoreInitializer : DropCreateDatabaseIfModelChanges<DataContext>
    //public class StoreInitializer : DropCreateDatabaseAlways<DataContext>
    {
        protected override void Seed(DataContext context)
        {
            // Data source was Wikipedia

            var nike = new Supplier();
            nike.Name = "Nike, Inc.";
            nike.Country = "USA";
            nike.NameOfCEO = "Mark Parker";
            nike.TypeOfBusiness = "Apparel";
            nike.YearStarted = 1971;

            context.Suppliers.Add(nike);

            var bom = new Supplier
            {
                Name = "Bombardier Recreational Products, Inc.",
                Country = "Canada",
                NameOfCEO = "Jose Boisjoli",
                TypeOfBusiness = "Recreational products",
                YearStarted = 1942
            };

            context.Suppliers.Add(bom);

            context.SaveChanges();
        }
    }
}
