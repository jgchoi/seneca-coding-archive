using Assignment3.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace Assignment3.Controllers
{
    public class InvoiceAdd
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]


        public string CustomerFirstName { get; set; }
        public string CustomerLastName { get; set; }

        public DateTime InvoiceDate { get; set; }

        [StringLength(70)]
        public string BillingAddress { get; set; }

        [StringLength(40)]
        public string BillingCity { get; set; }

        [StringLength(40)]
        public string BillingState { get; set; }

        [StringLength(40)]
        public string BillingCountry { get; set; }

        [StringLength(10)]
        public string BillingPostalCode { get; set; }

        [Column(TypeName = "numeric")]
        public decimal Total { get; set; }

      
    }

    public class InvoiceBase: InvoiceAdd
    {
        public int InvoiceId { get; set; }
    }

    public class InvoiceBase2 : InvoiceBase
    {
        public InvoiceBase2()
        {
            InvoiceLines = new List<InvoiceLineBase2>();
        }
        //Public virtual Customer Customer { get; set; }
        public string CustomerEmployeeFirstName { get; set; }
        public string CustomerEmployeeLastName { get; set; }
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<InvoiceLineBase2> InvoiceLines { get; set; }
    }

}

/*
 * ** Customer name
** Employee (sales rep) name
** collection of invoice line items
*** Track name
*** composer
*** media type name
*** album title
*** artist name
 * /
 * */
