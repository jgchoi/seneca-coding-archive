using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment6.Controllers
{
    public class AlbumAdd
    {
        [Required]
        [StringLength(160)]
        public string Title { get; set; }

        public int ArtistId { get; set; }
    }

    public class AlbumBase : AlbumAdd
    {
        [Key]
        public int AlbumId { get; set; }
        public string ArtistName { get; set; }
        public int TracksCount { get; set; }
    }

    public class AlbumWithTrack : AlbumBase
    {
        public AlbumWithTrack()
        {
            Tracks = new HashSet<TrackWithLink>();
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<TrackWithLink> Tracks { get; set; }
    }

    // ############################################################
    // Linked classes

    public class AlbumWithLink : AlbumWithMediaInfo
    {
        public Link Link { get; set; }

        // Duplicated identity field
        [JsonIgnore]
        public int Id { get; set; }
    }

    public class AlbumLinked : LinkedItem<AlbumWithLink>
    {
        public AlbumLinked(AlbumWithLink item) : base(item) { }
    }

    public class AlbumsLinked : LinkedCollection<AlbumWithLink>
    {
        public AlbumsLinked(IEnumerable<AlbumWithLink> collection) : base(collection) { }
    }

    // Media
    public class AlbumWithMediaInfo : AlbumWithTrack
    {
        public int PhotoLength { get; set; }
        public string ContentType { get; set; }
    }

    public class AlbumWithMedia : AlbumWithMediaInfo
    {
        public byte[] Photo { get; set; }

    }
}