using Lab5.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lab5.Controllers
{//List, add, base
    public class ArtistAdd
    {
        [Required, StringLength(100, MinimumLength = 2)]
        [Display(Name = "Artist or stage name")]
        public string Name { get; set; }
        [StringLength(100)]
        [Display(Name = "Birth name")]
        public string BirthName { get; set; }
        [DataType(DataType.Date)]
        public DateTime BirthOrStartDate { get; set; }
        [Required]
        [StringLength(50)]
        public string Genre { get; set; }
        [Range(1880, 2999)]
        [Display(Name = "Decade started")]
        public int StartDecade { get; set; }
    }


    public class ArtistAddForm
    {
        [Required, StringLength(100, MinimumLength = 2)]
        [Display(Name = "Artist or stage name")]
        public string Name { get; set; }
        [StringLength(100)]

        [Display(Name = "Birth name")]
        public string BirthName { get; set; }
        [Display(Name = "Birth or start date")]
        [DataType(DataType.Date)]
        public DateTime BirthOrStartDate { get; set; }
        [Display(Name = "Decade started")]
        [Range(1880, 2999)]
        public int StartDecade { get; set; }
        [Required]
        public SelectList Genre { get; set; }


    }

    public class ArtistBase : ArtistAdd
    {
        public int Id { get; set; }

    }

    public class ArtistList
    {
        public int Id { get; set; }
        [Required, StringLength(100, MinimumLength = 2)]
        public string Name { get; set; }


    }
}