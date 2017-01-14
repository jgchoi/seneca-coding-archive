using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;

namespace Assignment6
{
    public static class AutoMapperConfig
    {
        public static void RegisterMappings()
        {
            // Add map creation statements here
            // Mapper.CreateMap< FROM , TO >();

            // Disable AutoMapper v4.2.x warnings
#pragma warning disable CS0618
            Mapper.CreateMap<Models.Track, Controllers.TrackBase>();
            Mapper.CreateMap<Models.Album, Controllers.AlbumBase>();
            Mapper.CreateMap<Models.Artist, Controllers.ArtistBase>();
            Mapper.CreateMap<Models.Artist, Controllers.ArtistWithLink>()
                .ForMember(dest => dest.Id, opt => opt.MapFrom(src => src.ArtistId));
            Mapper.CreateMap<Models.Track, Controllers.TrackWithLink>()
               .ForMember(dest => dest.Id, opt => opt.MapFrom(src => src.TrackId));
            Mapper.CreateMap<Controllers.ArtistBase, Controllers.ArtistWithLink>()
               .ForMember(dest => dest.Id, opt => opt.MapFrom(src => src.ArtistId));
            Mapper.CreateMap<Models.Artist, Controllers.ArtistWithAlbum>();
            Mapper.CreateMap<Controllers.AlbumWithMedia, Controllers.AlbumWithLink>()
                .ForMember(dest => dest.Id, opt => opt.MapFrom(src => src.ArtistId));
            Mapper.CreateMap<Controllers.AlbumBase, Controllers.AlbumWithLink>()
                .ForMember(dest => dest.Id, opt => opt.MapFrom(src => src.AlbumId));
            Mapper.CreateMap<Models.Album, Controllers.AlbumWithMedia>();
            // AutoMapper create map statements

#pragma warning restore CS0618
        }
    }
}