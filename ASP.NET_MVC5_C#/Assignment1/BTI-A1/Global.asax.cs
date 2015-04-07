using AutoMapper;
using BTI_A1.Controllers;
using BTI_A1.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Optimization;
using System.Web.Routing;


namespace BTI_A1
{
    public class MvcApplication : System.Web.HttpApplication
    {

        protected void Application_Start()
        {


            AreaRegistration.RegisterAllAreas();
            FilterConfig.RegisterGlobalFilters(GlobalFilters.Filters);
            RouteConfig.RegisterRoutes(RouteTable.Routes);
            BundleConfig.RegisterBundles(BundleTable.Bundles);

            //Initial data for the app
            //Disabled after eanble-migrations
            System.Data.Entity.Database.SetInitializer(new Models.StoreInitializer());

            //Configure AutoMapper
            Mapper.CreateMap<Suggestion, SuggestionBase>();
            Mapper.CreateMap<Suggestion, SuggestionList>();
            Mapper.CreateMap<Suggestion, SuggestionBaseWithImage>();
            Mapper.CreateMap<Suggestion, SuggestionBaseWithFollowUps>();
            Mapper.CreateMap<SuggestionBase, SuggestionEditForm>();
            Mapper.CreateMap<SuggestionEdit, SuggestionEditForm>();
            Mapper.CreateMap<SuggestionAdd, Suggestion>();
            Mapper.CreateMap<FollowUp, FollowUpBase>();
            Mapper.CreateMap<FollowUp, FollowUpBaseWithSuggestionAndImage>();
            Mapper.CreateMap<FollowUpEdit, FollowUpEditForm>();
            
                 Mapper.CreateMap<FollowUpBaseWithSuggestionAndImage, FollowUpEditForm>();
            Mapper.CreateMap<FollowUpAdd, FollowUp>();
            Mapper.CreateMap<ProgramAdd, ProgramBase>();
            Mapper.CreateMap<CourseAdd, CourseBase>();
            Mapper.CreateMap<Course, CourseBase>();
            Mapper.CreateMap<Program, ProgramBase>();
            Mapper.CreateMap<ProgramAdd, Program>();
            Mapper.CreateMap<CourseAdd, Course>();
            Mapper.CreateMap<Course, CourseList>();
            Mapper.CreateMap<Program, ProgramList>();
        }
        protected void Application_EndRequest()
        {
            // Handling error conditions...
            // Inspiration: http://stackoverflow.com/a/9026907 

            var code = Context.Response.StatusCode;

            // Add more conditions here as you need them
            if (code == 404) { this.HandleError("NotFound"); }
            if (code >= 500) { this.HandleError("ServerError"); }
        }

        private void HandleError(string action)
        {
            // This method causes the Errors controller to handle the request
            // It creates the controller, then executes the desired action method

            // With some more code, it could also save the error,
            // and notify the web site programmer(s)

            // Clear the accumulated data out of the response object
            Response.Clear();

            // Create the route data configuration
            var rd = new RouteData();
            rd.Values["controller"] = "Errors";
            rd.Values["action"] = action;

            // Create then execute the controller method
            IController c = new BTI_A1.Controllers.ErrorsController();
            c.Execute(new RequestContext(new HttpContextWrapper(Context), rd));
        }

    }
}
