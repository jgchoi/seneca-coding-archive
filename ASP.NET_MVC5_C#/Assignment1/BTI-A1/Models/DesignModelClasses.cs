using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace BTI_A1.Models
{
    public class Program
    {
        //String property for program information
        public int Id { get; set; }
        
        [Required,StringLength(50)]
        public string Name { get; set; }

        [Required, StringLength(10)]
        public string Code { get; set; }

        [Required, StringLength(1000)]
        public string Description { get; set; }
        public string Credential { get; set; }

        //Many to Many Nav property to Course
        public ICollection<Course> Courses { get; set; }

        //Constructor
        public Program()
        {
            Courses = new List<Course>();
        }
    }

    public class Course
    {
        //String proeprty for program information
        public int Id { get; set; }

        [Required]
        public string Name { get; set; }

        [Required]
        public string Code { get; set; }

        [Required]
        public string Description { get; set; }

        //Many to Many Nav property to Program
        public ICollection<Program> Programs { get; set; }

        //Constructor
        public Course() 
        {
            Programs = new List<Program>();
        }
            
    }

    public class Suggestion
    {
        //Properties
        public int Id { get; set; }

        [DataType(DataType.DateTime)]
        public DateTime Timestamp { get; set; }


        [Required, StringLength(50, MinimumLength=5)]
        public string Title { get; set; }

        [Required, StringLength(1000, MinimumLength=10)]
        public string Description { get; set; }

        [Required]
        public string Program { get; set; }

        [Required]
        public string Course { get; set; }
        public byte[] Attachment { get; set; }
        public string ContentType { get; set; }
        public ICollection<FollowUp> FollowUps { get; set; }

        //Constructor
        public Suggestion()
        {
            FollowUps = new List<FollowUp>();
            Timestamp = DateTime.Now;
        }

    }

    public class FollowUp
    {
        public int Id { get; set; }

        [DataType(DataType.DateTime)]
        public DateTime Timestamp { get; set; }


        [Required, StringLength(50, MinimumLength = 5)]
        public string Title { get; set; }

        [Required, StringLength(1000, MinimumLength = 10)]
        public string Description { get; set; }
        public byte[] Attachment { get; set; }
        public string ContentType { get; set; }
        public Suggestion Suggestion { get; set; }

        //Constructor
        public FollowUp()
        {
            Timestamp = DateTime.Now;
        }
    }

}