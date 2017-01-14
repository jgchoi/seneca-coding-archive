using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;

namespace Assignment5
{
    public static class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // Add map creation statements here
            // Mapper.CreateMap< FROM , TO >();

            // Disable AutoMapper v4.2.x warnings
#pragma warning disable CS0618

            // Attention - AutoMapper create map statements
            
            Mapper.CreateMap<Controllers.CustomerAdd, Models.Customer>();
            Mapper.CreateMap<Models.Customer, Controllers.CustomerBase>();
            Mapper.CreateMap<Controllers.CustomerBase, Controllers.CustomerWithLink>()
               .ForMember(dest => dest.Id, opt => opt.MapFrom(src => src.CustomerId));

            Mapper.CreateMap<Models.Invoice, Controllers.InvoiceBase>();
            Mapper.CreateMap<Controllers.InvoiceBase, Controllers.InvoiceWithLink>()
               .ForMember(dest => dest.Id, opt => opt.MapFrom(src => src.InvoiceId));

#pragma warning restore CS0618
        }
    }
}