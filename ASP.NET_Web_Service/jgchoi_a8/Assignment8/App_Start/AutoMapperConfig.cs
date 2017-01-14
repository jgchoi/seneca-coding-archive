using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using Microsoft.AspNet.Identity.EntityFramework;

namespace Assignment8
{
    public static class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // Add map creation statements here
            // Mapper.CreateMap< FROM , TO >();

            // Disable AutoMapper v4.2.x warnings
#pragma warning disable CS0618

            // Attention 01 - AutoMapper added, here are the create map statements

            // AutoMapper create map statements

            // ############################################################
            // AppClaim

            Mapper.CreateMap<Models.AppClaim, Controllers.AppClaimBase>();
            Mapper.CreateMap<Controllers.AppClaimAdd, Models.AppClaim>();

            // ############################################################
            // User account management

            Mapper.CreateMap<IdentityUser, Controllers.MSUserAccountBase>();
            Mapper.CreateMap<IdentityUser, Controllers.MSUserAccountWithClaims>();
            Mapper.CreateMap<IdentityUserClaim, Controllers.MSClaimBase>();
            Mapper.CreateMap<IdentityUserClaim, Controllers.MSClaimList>();
#pragma warning restore CS0618
        }
    }
}