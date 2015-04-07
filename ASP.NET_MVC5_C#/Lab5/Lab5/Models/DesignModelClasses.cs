using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Data.Entity;
using System.Linq;
using System.Web;

namespace Lab5.Models
{
    //Store initializer
    public class StoreInitializer : CreateDatabaseIfNotExists<DataContext>
    {
        //creating genre object
        protected override void Seed(DataContext context)
        {
            //Add Genre - method 1
            var pop = new Genre { Name = "Pop" };
            context.Genres.Add(pop);
            //Add genre - method 2
            context.Genres.Add(new Genre { Name = "Country" });
            context.Genres.Add(new Genre { Name = "Classical" });
            context.Genres.Add(new Genre { Name = "Jazz" });
            context.Genres.Add(new Genre { Name = "Easy Listening" });
            context.Genres.Add(new Genre { Name = "Electronic" });
            context.Genres.Add(new Genre { Name = "Enka" });
            context.Genres.Add(new Genre { Name = "Folk" });
            context.Genres.Add(new Genre { Name = "German Folk" });
            context.Genres.Add(new Genre { Name = "Hip-Hop/Rap" });
            context.Genres.Add(new Genre { Name = "Children's Music" });
            context.Genres.Add(new Genre { Name = "Blues" });
            context.Genres.Add(new Genre { Name = "R&B Soul" });
            //end of adding genre, save data
            context.SaveChanges();
        }
    }
    public class Artist
    {
        public Artist()
        {
            this.Albums = new List<Album>();
            //birth date
            this.BirthOrStartDate = DateTime.Now;
            this.StartDecade = 2010;
        }
        public int Id { get; set; }
        [Required, StringLength(100, MinimumLength = 2)]
        public string Name { get; set; }
        [StringLength(100)]
        public string BirthName { get; set; }

        public DateTime BirthOrStartDate { get; set; }
        [Required]
        [StringLength(50)]
        public string Genre { get; set; }
        [Range(1880, 2999)]
        public int StartDecade { get; set; }
        public ICollection<Album> Albums { get; set; }
    }

    //Look up table
    public class Genre
    {
        public int Id { get; set; }
        public string Name { get; set; }
    }

    public class Album
    {
        public Album()
        {
            this.Songs = new List<Song>();
        }
        [Required, StringLength(100)]
        public string Producer { get; set; }
        [Required]
        [StringLength(50)]
        public string Genre { get; set; }
        public int Id { get; set; }
        [Required]
        [StringLength(50)]
        public string Name { get; set; }
        [Required]
        [StringLength(50)]
        public string Publisher { get; set; }
        [DataType(DataType.DateTime)]
        public DateTime ReleaseDate { get; set; }

        public string AlbumCoverURL { get; set; }

        public double Length { get; set; }

        [Required]
        public Artist Artist { get; set; }
        public ICollection<Song> Songs { get; set; }

    }

    public class Song
    {
        public int Id { get; set; }
        public string Name { get; set; }
        [StringLength(50)]
        public string Composer { get; set; }
        //Nullable datetime
        public DateTime? SingleReleaseDate { get; set; }
        [Range(1, 300)]
        public int TrackNumber { get; set; }
        [Required]
        [StringLength(50)]
        public string Genre { get; set; }

        [Required]
        public Album Album { get; set; }
    }
}