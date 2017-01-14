using Assignment3.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment3.Controllers
{
    public class EmployeeAdd
    {
        [Required]
        [StringLength(20)]
        public string LastName { get; set; }

        [Required]
        [StringLength(20)]
        public string FirstName { get; set; }

        [StringLength(30)]
        public string Title { get; set; }

        public DateTime? BirthDate { get; set; }

        public DateTime? HireDate { get; set; }

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

        [StringLength(60)]
        public string Email { get; set; }

        public int? Employee2EmployeeId { get; set; }
    }


    public class EmployeeBase : EmployeeAdd
    {
        public int EmployeeId { get; set; }

    }

    public class EmployeeBase2 : EmployeeBase
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public EmployeeBase2()
        {

            Employee1 = new List<EmployeeBase>();
        }

        public int? ReportsTo { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<EmployeeBase> Employee1 { get; set; }
        
       

        public virtual EmployeeBase Employee2 { get; set; }
    }

    public class EmployeeEditManager
    {
        public int EmployeeId { get; set; }
        public int Employee2EmployeeId { get; set; }
    }

    public class EmployeeEditDirectReport
    {
        public int EmployeeId { get; set; }
        public ICollection<int> Employee1 { get; set; }
    }


}