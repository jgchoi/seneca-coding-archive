using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace Assignment5.Controllers
{
    public class InvoiceAdd
    {


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

    public class InvoiceBase : InvoiceAdd
    {
        public int InvoiceId { get; set; }
    }

    public class InvoiceWithLink : InvoiceBase
    {
        public Link Link { get; set; }
        public int Id { get; set; }
    }

    public class InvoiceLinked : LinkedItem<InvoiceWithLink>
    {
        public InvoiceLinked(InvoiceWithLink item) : base(item) { }
    }

    public class InvoicesLinked : LinkedCollection<InvoiceWithLink>
    {
        public InvoicesLinked(IEnumerable<InvoiceWithLink> collection) : base(collection) { }
        public InvoiceAddTemplate Template = new InvoiceAddTemplate();
    }

    public class InvoiceAddTemplate
    {


        public string InvoiceDate { get { return "date format in yyyy-mm-dd hh:mm:ss"; } }

        [StringLength(70)]
        public string BillingAddress { get { return "string 70 char"; } }

        [StringLength(40)]
        public string BillingCity { get { return "string 40 char"; } }

        [StringLength(40)]
        public string BillingState { get { return "string 40 char"; } }

        [StringLength(40)]
        public string BillingCountry { get { return "string 40 char"; } }

        [StringLength(10)]
        public string BillingPostalCode { get { return "string 10 char"; } }

        [Column(TypeName = "numeric")]
        public string Total { get { return "Numbers"; } }
    }
}