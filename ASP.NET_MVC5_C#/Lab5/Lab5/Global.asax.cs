using AutoMapper;
using Lab5.Controllers;
using Lab5.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Optimization;
using System.Web.Routing;


namespace Lab5
{
    public class MvcApplication : System.Web.HttpApplication
    {
        protected void Application_Start()
        {
            AreaRegistration.RegisterAllAreas();
            FilterConfig.RegisterGlobalFilters(GlobalFilters.Filters);
            RouteConfig.RegisterRoutes(RouteTable.Routes);
            BundleConfig.RegisterBundles(BundleTable.Bundles);

            //DB Initializer
            System.Data.Entity.Database.SetInitializer(new Models.StoreInitializer());

            // Configure AutoMapper maps
            //Artist
            Mapper.CreateMap<Artist, ArtistBase>();
            Mapper.CreateMap<Artist, ArtistList>();
            Mapper.CreateMap<ArtistAdd, Artist>();

            //Album
            Mapper.CreateMap<Album, AlbumBase>();
            Mapper.CreateMap<Album, AlbumList>();
            Mapper.CreateMap<AlbumAdd, Album>();

            //Song
            Mapper.CreateMap<Song, SongList>();
            Mapper.CreateMap<Song, SongBase>();
            Mapper.CreateMap<SongAdd, Song>();
        }
    }
}
