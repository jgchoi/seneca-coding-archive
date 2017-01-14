using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment6.Controllers
{
    public class ArtistAdd
    {
        [StringLength(120)]
        public string Name { get; set; }
    }
    
    public class ArtistBase : ArtistAdd
    {
        [Key]
        public int ArtistId { get; set; }
        public int AlbumsCount { get; set; }
    }

    public class ArtistWithAlbum : ArtistBase
    {
        public ArtistWithAlbum()
        {
            Albums = new HashSet<AlbumWithLink>();
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<AlbumWithLink> Albums { get; set; }

    }

    // Linked
    public class ArtistWithLink : ArtistWithAlbum
    {
        public Link Link { get; set; }
        // Duplicated identity field
        [JsonIgnore]
        public int Id { get; set; }
    }

    public class ArtistLinked : LinkedItem<ArtistWithLink>
    {
        public ArtistLinked(ArtistWithLink item) : base(item) { }
    }

    public class ArtistsLinked : LinkedCollection<ArtistWithLink>
    {
        public ArtistsLinked(IEnumerable<ArtistWithLink> collection) : base(collection) { }
    }


    // Media
    public class ArtistWithMediaInfo : ArtistBase
    {
        public int PhotoLength { get; set; }
        public string ContentType { get; set; }
    }

    public class ArtistWithMedia : ArtistWithMediaInfo
    {
        public byte[] Photo { get; set; }
    }


}