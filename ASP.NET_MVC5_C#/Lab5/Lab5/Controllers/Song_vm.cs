using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lab5.Controllers
{
    public class SongAdd
    {

        public string Name { get; set; }
        [StringLength(50)]
        public string Composer { get; set; }
        //Nullable datetime
        [Display(Name = "Single Relesea Date")]
        [DataType(DataType.Date)]
        public DateTime? SingleReleaseDate { get; set; }
        [Range(1, 300)]
        [Display(Name = "Track Number")]
        public int TrackNumber { get; set; }
        [Required]
        [StringLength(50)]
        public string Genre { get; set; }

        [Required]
        public int AlbumId { get; set; }
    }
    public class SongAddForm
    {
        public string Name { get; set; }
        [StringLength(50)]
        public string Composer { get; set; }
        //Nullable datetime
        [Display(Name = "Single Relesea Date")]
        [DataType(DataType.Date)]
        public DateTime? SingleReleaseDate { get; set; }
        [Range(1, 300)]
        [Display(Name = "Track Number")]
        public int TrackNumber { get; set; }
        [Required]
        [StringLength(50)]
        public SelectList Genre { get; set; }

        [Required]
        public SelectList AlbumId { get; set; }
    }
    public class SongList
    {
        public int Id { get; set; }
        public string Name { get; set; }

    }
    public class SongBase : SongAdd
    {
        public int Id { get; set; }
        public string AlbumName { get; set; }
        public string AlbumArtistName { get; set; }
    }
}