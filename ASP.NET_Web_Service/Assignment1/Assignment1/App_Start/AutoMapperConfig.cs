using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assignment1.App_Start
{
    public static class AutoMapperConfig
    {
        public static void RegisterMappings()
        {

            Mapper.CreateMap<Models.Smartphone, Controllers.SmartphoneBase>();
            Mapper.CreateMap<Controllers.SmartphoneAdd, Models.Smartphone>();
        }
    }
}

