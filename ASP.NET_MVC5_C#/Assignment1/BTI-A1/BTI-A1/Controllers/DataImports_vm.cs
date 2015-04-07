using BTI_A1.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using CsvHelper;
using CsvHelper.Configuration;
using System.ComponentModel.DataAnnotations;

namespace BTI_A1.Controllers
{
    public class ProgramAdd
    {
        [Required, StringLength(50)]
        public string Name { get; set; }

        [Required, StringLength(10)]
        public string Code { get; set; }

        [Required, StringLength(1000)]
        public string Description { get; set; }
        public string Credential { get; set; }
        //Many to Many Nav property to Course
        public ICollection<Course> Courses { get; set; }
        public ProgramAdd()
        {
            Courses = new List<Course>();
        }
    }
    public class ProgramMap : CsvClassMap<ProgramAdd>
    {
        // This class customizes the property-to-column mappings

        // It identifies the properties that have different
        // column (field) names in the source CSV file

        public ProgramMap()
        {
            // First, map all the properties that have matching names
            AutoMap();
        }
    }

    public class ProgramBase : ProgramAdd
    {
        public int Id { get; set; }
    }

    public class CourseAdd
    {
        [Required, StringLength(50)]
        public string Name { get; set; }

        [Required, StringLength(10)]
        public string Code { get; set; }

        [Required, StringLength(1000)]
        public string Description { get; set; }
        public ICollection<Program> Programs { get; set; }

        //Constructor
        public CourseAdd()
        {
            Programs = new List<Program>();
        }
    }
    public class CourseMap : CsvClassMap<CourseAdd>
    {
        // This class customizes the property-to-column mappings

        // It identifies the properties that have different
        // column (field) names in the source CSV file

        public CourseMap()
        {
            // First, map all the properties that have matching names
            AutoMap();
        }
    }

    public class CourseBase : CourseAdd
    {
        public int Id { get; set; }
    }

    public class CourseList
    {
        public int Id { get; set; }
        public string Code { get; set; }
        public string Name { get; set; }
        public string CodeAndName
        {
            get
            {
                return string.Format("{0} - {1}", this.Code, this.Name);
            }
        }
    }

    public class ProgramList
    {
        public int Id { get; set; }
        public string Code { get; set; }
        public string Name { get; set; }
        public string CodeAndName
        {
            get
            {
                return string.Format("{0} - {1}", this.Code, this.Name);
            }
        }
    }


}