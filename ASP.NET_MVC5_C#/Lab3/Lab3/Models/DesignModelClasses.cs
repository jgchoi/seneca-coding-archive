using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Lab3.Models
{
    public class Survey
    {
        //Properties
        public int Id { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }
        public ICollection<String> Courses { get; set; }
        public string PaceOfLearning { get; set; }
        public ICollection<String> FavouriteTopics { get; set; }
        public string Comments { get; set; }

        //Constructor
        public Survey() 
        {
            this.Courses = new List<String>();
            this.FavouriteTopics = new List<String>(); 
        }
    
    }
}