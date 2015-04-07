using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Lab4.Controllers
{
    // For a user interface select/list control
    public class SupplierList
    {
        public int Id { get; set; }
        public string Name { get; set; }
}

    // Base class with most properties
    public class SupplierBase
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string TypeOfBusiness { get; set; }
        public string Country { get; set; }
        public string NameOfCEO { get; set; }
        public int YearStarted { get; set; }
    }

}
