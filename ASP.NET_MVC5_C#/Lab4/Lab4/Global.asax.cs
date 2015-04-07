using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Optimization;
using System.Web.Routing;
// new...
using AutoMapper;

namespace Lab4
{
    public class MvcApplication : System.Web.HttpApplication
    {
        protected void Application_Start()
        {
            AreaRegistration.RegisterAllAreas();
            FilterConfig.RegisterGlobalFilters(GlobalFilters.Filters);
            RouteConfig.RegisterRoutes(RouteTable.Routes);
            BundleConfig.RegisterBundles(BundleTable.Bundles);

            // Initial data for the app
            System.Data.Entity.Database.SetInitializer(new Models.StoreInitializer());

            // Configure AutoMapper maps

            Mapper.CreateMap<Models.Supplier, Controllers.SupplierBase>();
            Mapper.CreateMap<Models.Supplier, Controllers.SupplierList>();
            Mapper.CreateMap<Models.Product, Controllers.ProductBase>();
            Mapper.CreateMap<Controllers.ProductBase, Models.Product>();
            Mapper.CreateMap<Controllers.ProductAdd, Models.Product>();
            // ...add more here...

        }
    }
}
