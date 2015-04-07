using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
//For selectlist
using System.Web.Mvc;

namespace Lab3.Controllers
{

    public class SurveyAddForm
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public SelectList Courses { get; set; }
        public SelectList PaceOfLearning { get; set; }
        public SelectList FavouriteTopics { get; set; }
        public string Comments { get; set; }
    }

    public class SurveyAdd
    {
        public SurveyAdd()
        {
            this.Courses = new List<string>();
            this.FavouriteTopics = new List<string>();
        }

        public string Name { get; set; }
        public int Age { get; set; }
        public IEnumerable<String> Courses { get; set; }
        public string PaceOfLearning { get; set; }
        public IEnumerable<String> FavouriteTopics { get; set; }
        public string Comments { get; set; }
           
    }

    public class SurveyFull : SurveyAdd
    {
        public int Id { get; set; }

    }
}