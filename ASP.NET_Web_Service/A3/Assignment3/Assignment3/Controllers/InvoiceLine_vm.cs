using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace Assignment3.Controllers
{
    public class InvoiceLineAdd
    {

        public int TrackId { get; set; }

        [Column(TypeName = "numeric")]
        public decimal UnitPrice { get; set; }

        public int Quantity { get; set; }
    }

    public class InvoiceLineBase : InvoiceLineAdd
    {
        public int InvoiceLineId { get; set; }

    }

    public class InvoiceLineBase2 : InvoiceLineBase
    {
        public string TrackName { get; set; }
        public string TrackComposer { get; set; }
        public string TrackAlbumArtistName { get; set; }
        public string TrackMediaTypeName { get; set; }
    }


}
