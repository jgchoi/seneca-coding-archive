using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace Assignment6.Controllers
{
    public class TrackAdd
    {

        [Required]
        [StringLength(200)]
        public string Name { get; set; }

        public int? AlbumId { get; set; }

        public int MediaTypeId { get; set; }

        public int? GenreId { get; set; }

        [StringLength(220)]
        public string Composer { get; set; }

        public int Milliseconds { get; set; }

        public int? Bytes { get; set; }

        [Column(TypeName = "numeric")]
        public decimal UnitPrice { get; set; }

    }

    public class TrackBase : TrackAdd
    {
        [Key]
        public int TrackId { get; set; }

        public string AlbumTitle { get; set; }
        public string AlbumArtistName { get; set; }
        public string MediaTypeName { get; set; }
    }

    public class TrackWithMediaInfo : TrackBase
    {
        public int ClipLength { get; set; }
        public string ContentType { get; set; }
    }

    public class TrackWithMedia : TrackWithMediaInfo
    {
        public byte[] Clip { get; set; }
    }

    public class TrackWithLink : TrackBase
    {
        public Link Link { get; set; }

        // Duplicated identity field
        [JsonIgnore]
        public int Id { get; set; }
    }

    public class TrackLinked : LinkedItem<TrackWithLink>
    {
        public TrackLinked(TrackWithLink item) : base(item) { }
    }

    public class TracksLinked : LinkedCollection<TrackWithLink>
    {
        public TracksLinked(IEnumerable<TrackWithLink> collection) : base(collection) { }
    }

}