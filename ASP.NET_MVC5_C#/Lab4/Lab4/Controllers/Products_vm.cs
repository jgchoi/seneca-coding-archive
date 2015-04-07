using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using System.Web.Mvc;

namespace Lab4.Controllers
{
    public class ProductAddForm
    {
     
        public string Name { get; set; }
        public string ProductId { get; set; }
        public SelectList Size { get; set; }
        public string UPC { get; set; }
        public double MSRP { get; set; }
        public SelectList Supplier { get; set; }
    }

    public class ProductAdd
    {
        public string Name { get; set; }
        public int SupplierId { get; set; }
        public string ProductId { get; set; }
        public string Size { get; set; }
        public string UPC { get; set; }
        public double MSRP { get; set; }


    }

    public class ProductBase : ProductAdd
    {
        public int Id { get; set; }
        public string SupplierName { get; set; }
    }

    public class ProductBaseWithSupplier : ProductBase
    {
        // Read the specifications
    }

}
