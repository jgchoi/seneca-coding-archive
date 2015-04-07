using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Lab4.Models
{
    public class Supplier
    {
        public Supplier()
        {
            this.Products = new List<Product>();
        }

        public int Id { get; set; }
        public string Name { get; set; }
        public string TypeOfBusiness { get; set; }
        public string Country { get; set; }
        public string NameOfCEO { get; set; }
        public int YearStarted { get; set; }

        public ICollection<Product> Products { get; set; }
    }

    public class Product
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string ProductId { get; set; }
        public string Size { get; set; }
        public string UPC { get; set; }
        public double MSRP { get; set; }

        // Read the specifications to learn about the other attributes

        public Supplier Supplier { get; set; }
    }

}
