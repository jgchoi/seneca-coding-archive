using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lab5.Controllers
{
    public class AlbumAdd
    {
        [Required]
        [StringLength(50)]
        public string Name { get; set; }

        [DataType(DataType.Date)]
        [Display(Name = "Release Date")]
        public DateTime ReleaseDate { get; set; }

        [Required]
        [StringLength(50)]
        public string Genre { get; set; }

        public double Length { get; set; }

        [Required, StringLength(100)]
        public string Producer { get; set; }

        [Display(Name = "Album Cover")]
        public string AlbumCoverURL { get; set; }

        [Required]
        [StringLength(50)]
        public string Publisher { get; set; }

        [Required]
        public int ArtistId { get; set; }
    }
    public class AlbumAddForm
    {
        [Required]
        [StringLength(50)]
        [Display(Name = "Album Name")]
        public string Name { get; set; }

        [DataType(DataType.Date)]
        [Display(Name = "Release Date")]
        public DateTime ReleaseDate { get; set; }

        [Required]
        [StringLength(50)]
        public SelectList Genre { get; set; }

        public double Length { get; set; }

        [Required, StringLength(100)]
        public string Producer { get; set; }
        [Display(Name = "Album Cover URL")]
        public string AlbumCoverURL { get; set; }

        [Required]
        [StringLength(50)]
        public string Publisher { get; set; }

        [Required]
        [Display(Name = "Artist Name")]
        public SelectList ArtistId { get; set; }
    }

    public class AlbumBase : AlbumAdd
    {
        public int Id { get; set; }
        public string ArtistName { get; set; }
    }

    public class AlbumList
    {
        public int Id { get; set; }

        public string Name { get; set; }
        public string ArtistName { get; set; }
        public string AlbumAndArtist
        {
            get
            {
                return string.Format("{0} - {1}", this.Name, this.ArtistName);
            }
        }



    }
}