using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using Lab5.Models;
using AutoMapper;

namespace Lab5.Controllers
{
    public class Manager
    {
        private DataContext ds = new DataContext();

        public IEnumerable<String> AllGenres()
        {
            return ds.Genres.OrderBy(g => g.Name).Select(g => g.Name).ToList();
        }

        public ArtistBase AddArtists(ArtistAdd newItem)
        {
            ArtistBase result;

            var addedItem = new Artist();

            addedItem = Mapper.Map<Artist>(newItem);
            ds.Artists.Add(addedItem);
            ds.SaveChanges();

            result = Mapper.Map<ArtistBase>(addedItem);

            // Return the result
            return result;
        }
        public IEnumerable<ArtistBase> AllArtists()
        {
            var fetchedObjects = ds.Artists.OrderBy(i => i.Name);
            return Mapper.Map<IEnumerable<ArtistBase>>(fetchedObjects);
        }

        public IEnumerable<ArtistList> AllArtistsList()
        {
            var fetchedObjects = ds.Artists.OrderBy(i => i.Name);
            return Mapper.Map<IEnumerable<ArtistList>>(fetchedObjects);
        }
        public AlbumBase AddAlbum(AlbumAdd newItem)
        {
            AlbumBase result;

            var addedItem = new Album();

            addedItem = Mapper.Map<Album>(newItem);
            //validate artistId
            if (ds.Artists.Find(newItem.ArtistId) != null)
            {
                addedItem.Artist = ds.Artists.Find(newItem.ArtistId);
                ds.Albums.Add(addedItem);
                ds.SaveChanges();
            }
            result = Mapper.Map<AlbumBase>(addedItem);

            // Return the result
            return result;
        }
        public IEnumerable<AlbumBase> AllAlbums()
        {
            //Spec:use Include
            var fetchedObjects = ds.Albums.Include("Artist").OrderBy(i => i.Name);
            return Mapper.Map<IEnumerable<AlbumBase>>(fetchedObjects);
        }
        public IEnumerable<AlbumList> AllAlbumsList()
        {
            var fetchedObjects = ds.Albums.Include("Artist").OrderBy(i => i.Name);
            return Mapper.Map<IEnumerable<AlbumList>>(fetchedObjects);
        }
        public SongBase AddSong(SongAdd newItem)
        {
            SongBase result;

            var addedItem = new Song();
            Album temp = ds.Albums.Include("Artist").SingleOrDefault(i => i.Id == newItem.AlbumId);
            //validate album id
            if (temp != null)
            {

                addedItem = Mapper.Map<Song>(newItem);
                addedItem.Album = temp;
                ds.Songs.Add(addedItem);
                ds.SaveChanges();
            }
            result = Mapper.Map<SongBase>(addedItem);

            // Return the result
            return result;
        }
        public IEnumerable<SongBase> AllSongs()
        {
            var fetchedObjects = ds.Songs.Include("Album.Artist").OrderBy(i => i.Name);
            return Mapper.Map<IEnumerable<SongBase>>(fetchedObjects);

        }
        public IEnumerable<SongList> AllSongsList()
        {
            var fetchedObjects = ds.Songs.OrderBy(i => i.Name);
            return Mapper.Map<IEnumerable<SongList>>(fetchedObjects);
        }

    }
}