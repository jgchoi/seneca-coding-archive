using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assign10.Controllers
{
    public class SharerAdd
    {

        [Required, StringLength(200)]
        public string Username { get; set; }

        [Required, StringLength(200)]
        public string AccessLevel { get; set; }
        [Range(1, UInt32.MaxValue)]
        public int ProjectId { get; set; }

    }

    public class SharerBase
    {
        public int Id { get; set; }
        public DateTime DateUpdated { get; set; }
    }
}