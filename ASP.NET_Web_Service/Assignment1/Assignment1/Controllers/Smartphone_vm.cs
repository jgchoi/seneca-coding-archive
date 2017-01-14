using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment1.Controllers
{
    public class SmartphoneAdd
    {
        public SmartphoneAdd()
        {
            ReleaseDate = DateTime.Now.AddYears(-30);
        }
        
        //prop tab tab

        [Required, StringLength(50)]
        public string Name { get; set; }
        [Required, StringLength(50)]
        public string Manufacture { get; set; }
        [Required, Range(0, 10)]
        public double ScreenSize { get; set; }
        public DateTime ReleaseDate { get; set; }
    }

    public class SmartphoneBase : SmartphoneAdd
    {
        public SmartphoneBase()
        {
            ReleaseDate = DateTime.Now.AddYears(-30);
        }

        [Key]
        public int Id { get; set; }
    }
}