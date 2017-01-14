using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment6.Models;

namespace Assignment6.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        public Manager()
        {
            // If necessary, add constructor code here

            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            ds.Configuration.LazyLoadingEnabled = false;
        }

        // Track
        public IEnumerable<TrackBase> TrackGetAll()
        {
            var c = ds.Tracks
                .Include("Album")
                .Include("Album.Artist")
                .Include("MediaType")
                .OrderBy(e => e.Name);

            return Mapper.Map<IEnumerable<TrackBase>>(c);
        }

        // Artist
        public IEnumerable<ArtistBase> ArtistGetAll()
        {
            var c = ds.Artists
                .Include("Albums")
                .OrderBy(a => a.Name)
                .Take(25);

            return Mapper.Map<IEnumerable<ArtistBase>>(c);
        }

        public ArtistWithAlbum ArtistGetById(int id)
        {
            var o = ds.Artists
                   .Include("Albums")
                    .SingleOrDefault(e => e.ArtistId == id);
            return (o == null) ? null : Mapper.Map<ArtistWithAlbum>(o);
        }

        // Album
        public IEnumerable<AlbumBase> AlbumGetAll()
        {
            var c = ds.Albums
                .Include("Artist")
                .Include("Tracks")
                .OrderBy(a => a.Title)
                .Take(25);

            return Mapper.Map<IEnumerable<AlbumBase>>(c);
        }

        public AlbumWithMedia AlbumGetById(int id)
        {
            var o = ds.Albums
                   .Include("Artist")
                   .Include("Tracks")
                    .SingleOrDefault(e => e.AlbumId == id);
            return (o == null) ? null : Mapper.Map<AlbumWithMedia>(o);
        }

        public bool AlbumSetPhoto(int id, string contentType, byte[] photo)
        {
            // Notice the return type of this method - bool
            // This is an incremental attempt at improving the command pattern
            // In the controller, we could use the return value, if we wished

            // Ensure that we can continue
            if (string.IsNullOrEmpty(contentType) | photo == null) { return false; }

            // Attempt to find the matching object
            var storedItem = ds.Albums.Find(id);

            // Ensure that we can continue
            if (storedItem == null) { return false; }

            // Save the photo
            storedItem.ContentType = contentType;
            storedItem.Photo = photo;

            // Attempt to save changes
            // Do you understand the following? If not, ask
            return (ds.SaveChanges() > 0) ? true : false;
        }

    }
}