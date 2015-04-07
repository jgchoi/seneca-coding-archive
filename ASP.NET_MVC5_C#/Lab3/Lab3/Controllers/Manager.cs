using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

//To use Biggy
using System.IO;
using Biggy.Core;
using Biggy.Data.Json;
using AutoMapper;
using Lab3.Models;


namespace Lab3.Controllers
{
    public class Manager
    {
        // Private fields that point to the data store and the collection(s)
        private JsonStore<Survey> store;
        private BiggyList<Survey> surveys;

        //Constructor
        public Manager()
        {
            //Configure AutoMapper
            Mapper.CreateMap<Survey, SurveyAdd>();
            Mapper.CreateMap<Survey, SurveyAddForm>();
            Mapper.CreateMap<Survey, SurveyFull>();
            Mapper.CreateMap<Survey, SurveyAdd>();
            Mapper.CreateMap<SurveyAdd, Survey>();
            //Path to store Biggy!
            var localData = HttpContext.Current.Server.MapPath("~/App_Data");

            //Open store
            store = new JsonStore<Survey>(localData, "bti420","surveys");

            //Connect collection
            surveys = new BiggyList<Survey>(store);
        }

        

        //Property for list of surveys
        public IEnumerable<SurveyFull> AllSurveys
        {
            get { return Mapper.Map<IEnumerable<SurveyFull>>(surveys.OrderBy(nm => nm.Name)); }
        }


        //adding method
        public SurveyFull AddSurvey(SurveyAdd newItem)
        {
            //New id
            int newId = (surveys.Count > 0) ? newId = surveys.Max(id => id.Id) + 1 : 1;

            //new item w/ Mapper
            Survey addedItem;
            addedItem       = Mapper.Map<Survey>(newItem);
            addedItem.Id    = newId;

            //Add new item
            surveys.Add(addedItem);

            //return value
            return Mapper.Map<SurveyFull>(addedItem);
        }

        public SurveyFull GetSurveyById(int id)
        {
            //Attempt to fetch the item
            var fetchedObject = surveys.SingleOrDefault(i => i.Id == id);

            //return the result
            return (fetchedObject == null) ? null : Mapper.Map<SurveyFull>(fetchedObject);

        }

        //Selectlist strings
        public IEnumerable<string> UI_Courses()
        {
            return new List<string>() { "BTP400", "BTN415", "BTI420", "BTS430", "BTC440" };

        }

        public IEnumerable<string> UI_PaceOfLearning()
        {
            return new List<string>() { "Too slow", "Slow", "Just right", "Fast", "Too fast"};

        }
        public IEnumerable<string> UI_FavouriteTopics()
        {
            return new List<string>() 
            {
                "Visual Studio 2013 developer tool",
                "C# language",
                ".NET Framework class library",
                "Learning and applying the MVC pattern",
                "Collection classes",
                "LINQ - language integrated query",
                "View model classes",
                "Data persistence",
                "Scaffolding",
                "HTML Helpers"
            };

        }

    }
}