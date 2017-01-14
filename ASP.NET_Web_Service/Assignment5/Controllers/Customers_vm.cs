using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment5.Controllers
{
    public class CustomerAdd
    {

        [Required]
        [StringLength(40)]
        public string FirstName { get; set; }

        [Required]
        [StringLength(20)]
        public string LastName { get; set; }

        [StringLength(80)]
        public string Company { get; set; }

        [StringLength(70)]
        public string Address { get; set; }

        [StringLength(40)]
        public string City { get; set; }

        [StringLength(40)]
        public string State { get; set; }

        [StringLength(40)]
        public string Country { get; set; }

        [StringLength(10)]
        public string PostalCode { get; set; }

        [StringLength(24)]
        public string Phone { get; set; }

        [StringLength(24)]
        public string Fax { get; set; }

        [Required]
        [StringLength(60)]
        public string Email { get; set; }

        public int? SupportRepId { get; set; }

    }

    public class CustomerBase : CustomerAdd
    {
        [Key]
        public int CustomerId { get; set; }

        //employee support representative

        public string EmployeeFirstName { get; set; }
        public string EmployeeLastName { get; set; }
    }

    public class CustomerWithLink : CustomerBase
    {
        public Link Link { get; set; }
        public int Id { get; set; }
    }

    public class CustomerLinked : LinkedItem<CustomerWithLink>
    {
        public CustomerLinked(CustomerWithLink item) : base(item) { }
    }

    public class CustomersLinked : LinkedCollection<CustomerWithLink>
    {


        public CustomersLinked(IEnumerable<CustomerWithLink> collection) : base(collection) { }
        public CustomerAddTemplate template = new CustomerAddTemplate();
    }

    public class CustomerEditContactInfo
    {
        [Key]
        public int CustomerId { get; set; }

        [StringLength(70)]
        public string Address { get; set; }

        [StringLength(40)]
        public string City { get; set; }

        [StringLength(40)]
        public string State { get; set; }

        [StringLength(40)]
        public string Country { get; set; }

        [StringLength(10)]
        public string PostalCode { get; set; }

        [StringLength(24)]
        public string Phone { get; set; }

        [StringLength(24)]
        public string Fax { get; set; }
    }

    public class CustomerEditSupportRep
    {
        public int CustomerId { get; set; }
        public int SupportRepId { get; set; }
    }

    public class CustomerAddTemplate
    {
        [Required]
        [StringLength(40)]
        public string FirstName { get { return "String 40 char"; } }

        [Required]
        [StringLength(20)]
        public string LastName { get { return "String 20 char"; } }

        [StringLength(80)]
        public string Company { get { return "String 80 char"; } }

        [StringLength(70)]
        public string Address { get { return "String 70 char"; } }

        [StringLength(40)]
        public string City { get { return "String 40 char"; } }

        [StringLength(40)]
        public string State { get { return "String 40 char"; } }

        [StringLength(40)]
        public string Country { get { return "String 40 char"; } }

        [StringLength(10)]
        public string PostalCode { get { return "String 10 char"; } }

        [StringLength(24)]
        public string Phone { get { return "String 24 char"; } }

        [StringLength(24)]
        public string Fax { get { return "String 24 char"; } }

        [Required]
        [StringLength(60)]
        public string Email { get { return "String 60 char"; } }

        public string SupportRepId { get { return "Optional Employee Id";} }
    }


}