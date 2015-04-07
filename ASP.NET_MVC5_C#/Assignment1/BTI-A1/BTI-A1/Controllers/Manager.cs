using AutoMapper;
using BTI_A1.Models;
using CsvHelper;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;

namespace BTI_A1.Controllers
{
    public class Manager
    {
        private ApplicationDbContext ds = new ApplicationDbContext();

        //#####################################################################
        //Program & Course
        public IEnumerable<ProgramList> GetAllProgramsList()
        {
            var fetchedObjects = ds.Programs.OrderBy(nm => nm.Code);

            return Mapper.Map<IEnumerable<ProgramList>>(fetchedObjects);
        }

        public IEnumerable<CourseList> GetAllCoursesList()
        {
            var fetchedObjects = ds.Courses.OrderBy(nm => nm.Code);

            return Mapper.Map<IEnumerable<CourseList>>(fetchedObjects);
        }

        //#####################################################################
        //Suggestion
        public SuggestionBase EditSuggestion(SuggestionEdit newItem)
        {
            var fetchedObject = ds.Suggestions.Include("FollowUps").SingleOrDefault(a => a.Id == newItem.Id);
            if (fetchedObject == null)
            {
                return null;
            }
            else
            {
                ds.Entry(fetchedObject).CurrentValues.SetValues(newItem);
                ds.SaveChanges();

                return Mapper.Map<SuggestionBase>(fetchedObject);
            }
        }
        public void deleteSuggestionById(int id)
        {
            //Find suggestion
            var removedItem = ds.Suggestions.Find(id);

            //Find follow ups
            var removedFollowUps = ds.FollowUps.Where(a => a.Suggestion.Id == removedItem.Id);

            //delete followups
            foreach (var item in removedFollowUps)
            {
                ds.FollowUps.Remove(item);
            }

            //delete suggestion
            ds.Suggestions.Remove(removedItem);

            //save!
            ds.SaveChanges();
        }

        public SuggestionBaseWithFollowUps GetSuggestionByIdWithFollowUps(int id)
        {
            var fetchedObject = ds.Suggestions.Include("FollowUps").SingleOrDefault(a => a.Id == id);
            return (fetchedObject == null) ? null : Mapper.Map<SuggestionBaseWithFollowUps>(fetchedObject);
        }

        public SuggestionBase GetSuggestionById(int id)
        {
            var fetchedObject = ds.Suggestions.Find(id);

            return (fetchedObject == null) ? null : Mapper.Map<SuggestionBase>(fetchedObject);
        }
        public SuggestionBaseWithImage GetSuggestionByIdWithImage(int id)
        {
            var fetchedObject = ds.Suggestions.Find(id);

            return (fetchedObject == null) ? null : Mapper.Map<SuggestionBaseWithImage>(fetchedObject);
        }

        public SuggestionBase AddNewSuggestion(SuggestionAdd newItem)
        {
            //add new item variable
            var addedItem = new Suggestion();

            //Convert suggestionAdd to suggestion
            addedItem = Mapper.Map<Suggestion>(newItem);

            //find program information & course information
            addedItem.Program = ds.Programs.Find(newItem.ProgramId).Name;
            addedItem.Course = ds.Courses.Find(newItem.CourseId).Name;

            //Handle the uploaded image
            //Add attachment only if there is image
            if (newItem.AttachmentUpload != null)
            {
                byte[] attachmentBytes = new byte[newItem.AttachmentUpload.ContentLength];
                newItem.AttachmentUpload.InputStream.Read(attachmentBytes, 0, newItem.AttachmentUpload.ContentLength);

                //ojbect property
                addedItem.Attachment = attachmentBytes;
                addedItem.ContentType = newItem.AttachmentUpload.ContentType;
            }
            //insert into data & save
            ds.Suggestions.Add(addedItem);
            ds.SaveChanges();

            return (addedItem == null) ? null : Mapper.Map<SuggestionBase>(addedItem);
        }

        public IEnumerable<SuggestionList> GetAllSuggestionsList()
        {
            var fetchedObjects = ds.Suggestions.OrderBy(nm => nm.Id);

            return Mapper.Map<IEnumerable<SuggestionList>>(fetchedObjects);
        }

        public IEnumerable<SuggestionBase> GetAllSuggestions()
        {
            var fetchedObjects = ds.Suggestions.OrderBy(nm => nm.Id);

            return Mapper.Map<IEnumerable<SuggestionBase>>(fetchedObjects);
        }

        //#####################################################################
        //Followup
        public FollowUpBaseWithSuggestionAndImage GetFollowUpByIdWithSuggestion(int id)
        {
            var fetchedObject = ds.FollowUps.Include("Suggestion").SingleOrDefault(a => a.Id == id);
            return (fetchedObject == null) ? null : Mapper.Map<FollowUpBaseWithSuggestionAndImage>(fetchedObject);
        }
        public FollowUpBase AddNewFollowUp(FollowUpAdd newItem)
        {
            //Addeditem variable
            var addedItem = new FollowUp();

            //Insert value
            addedItem = Mapper.Map<FollowUp>(newItem);

            //Insert suggestion object
            addedItem.Suggestion = ds.Suggestions.Find(newItem.SuggestionId);
            addedItem.Suggestion.FollowUps.Add(addedItem);

            //Handle the uploaded image
            //Add attachment only if there is image
            if (newItem.AttachmentUpload != null)
            {
                byte[] attachmentBytes = new byte[newItem.AttachmentUpload.ContentLength];
                newItem.AttachmentUpload.InputStream.Read(attachmentBytes, 0, newItem.AttachmentUpload.ContentLength);

                //ojbect property
                addedItem.Attachment = attachmentBytes;
                addedItem.ContentType = newItem.AttachmentUpload.ContentType;
            }

            ds.FollowUps.Add(addedItem);

            ds.SaveChanges();

            return Mapper.Map<FollowUpBase>(addedItem);
        }

        public IEnumerable<FollowUpBaseWithSuggestionAndImage> GetAllFollowUps()
        {
            var fetchedObjects = ds.FollowUps.Include("Suggestion").OrderBy(nm => nm.Id);
            return Mapper.Map<IEnumerable<FollowUpBaseWithSuggestionAndImage>>(fetchedObjects);
        }

        public void deleteFollowUpById(int id)
        {
            //Find Followup object
            var removedItem = ds.FollowUps.Include("Suggestion").SingleOrDefault(a => a.Id == id);

            //Remove followup object in suggestion
            var suggestionObject = removedItem.Suggestion;
            suggestionObject.FollowUps.Remove(removedItem);

            //delete suggestion
            ds.FollowUps.Remove(removedItem);

            //save!
            ds.SaveChanges();
        }
        public FollowUpBaseWithSuggestionAndImage EditFollowUp(FollowUpEdit newItem)
        {
            var fetchedObject = ds.FollowUps.Include("Suggestion").SingleOrDefault(a => a.Id == newItem.Id);
            if (fetchedObject == null)
            {
                return null;
            }
            else
            {
                ds.Entry(fetchedObject).CurrentValues.SetValues(newItem);
                ds.SaveChanges();

                return Mapper.Map<FollowUpBaseWithSuggestionAndImage>(fetchedObject);
            }
        }

        //#####################################################################
        //Dataimports
        public IEnumerable<ProgramBase> ReadProgramsFromCSV()
        {
            // File system path to the data file (in this project's App_Data folder)
            string path = HttpContext.Current.Server.MapPath("~/App_Data/ict-programs.csv");

            // Create a stream reader object, to read from the file system
            StreamReader sr = File.OpenText(path);

            // Create the CsvHelper object
            var csv = new CsvReader(sr);

            // Configure the mapping classes (if it exists)
            csv.Configuration.RegisterClassMap<ProgramMap>();

            // Configure a collection to hold the results
            List<ProgramAdd> results = new List<ProgramAdd>();

            // Go through the data file
            while (csv.Read())
            {
                // Read one line in the source file
                ProgramAdd qb = csv.GetRecord<ProgramAdd>();

                results.Add(qb);
            }

            // Clean up
            sr.Close();
            sr = null;

            // Return the results
            return Mapper.Map<IEnumerable<ProgramBase>>(results);

        }
        public IEnumerable<CourseBase> ReadCoursesFromCSV()
        {
            // File system path to the data file (in this project's App_Data folder)
            string path = HttpContext.Current.Server.MapPath("~/App_Data/ict-courses-bsd.csv");

            // Create a stream reader object, to read from the file system
            StreamReader sr = File.OpenText(path);

            // Create the CsvHelper object
            var csv = new CsvReader(sr);

            // Configure the mapping classes (if it exists)
            csv.Configuration.RegisterClassMap<CourseMap>();

            // Configure a collection to hold the results
            List<CourseAdd> results = new List<CourseAdd>();

            // Go through the data file
            while (csv.Read())
            {
                // Read one line in the source file
                CourseAdd qb = csv.GetRecord<CourseAdd>();

                results.Add(qb);
            }

            // Clean up
            sr.Close();
            sr = null;

            // Return the results
            return Mapper.Map<IEnumerable<CourseBase>>(results);

        }

        public void DeletePrograms()
        {
            while (ds.Programs.Count() > 0)
            {
                // Get an object
                var qb = ds.Programs.First();
                // Remove it, and save changes
                ds.Programs.Remove(qb);
                ds.SaveChanges();
            }
        }
        public void DeleteCourses()
        {
            while (ds.Courses.Count() > 0)
            {
                // Get an object
                var qb = ds.Courses.First();
                // Remove it, and save changes
                ds.Courses.Remove(qb);
                ds.SaveChanges();
            }
        }

        public IEnumerable<CourseBase> GetAllCourses()
        {
            var fetchedObjects = ds.Courses.OrderBy(nm => nm.Id);

            return Mapper.Map<IEnumerable<CourseBase>>(fetchedObjects);
        }

        public IEnumerable<ProgramBase> GetAllPrograms()
        {
            var fetchedObjects = ds.Programs.OrderBy(nm => nm.Id);

            return Mapper.Map<IEnumerable<ProgramBase>>(fetchedObjects);
        }

        public void LoadProgramFromCSV()
        {
            if (!(ds.Programs.Count() > 0))
            {

                // File system path to the data file (in this project's App_Data folder)
                string path = HttpContext.Current.Server.MapPath("~/App_Data/ict-programs.csv");

                // Create a stream reader object, to read from the file system
                StreamReader sr = File.OpenText(path);

                // Create the CsvHelper object
                var csv = new CsvReader(sr);

                // Configure the mapping classes (if it exists)
                csv.Configuration.RegisterClassMap<ProgramMap>();

                // Go through the data file
                while (csv.Read())
                {
                    // Read one line in the source file into a new object
                    ProgramAdd qb = csv.GetRecord<ProgramAdd>();

                    // Add the new object to the data store
                    ds.Programs.Add(Mapper.Map<Program>(qb));
                }

                ds.SaveChanges();

                // Clean up
                sr.Close();
                sr = null;
            }
        }
        public void LoadCourseFromCSV()
        {
            if (!(ds.Courses.Count() > 0))
            {

                // File system path to the data file (in this project's App_Data folder)
                string path = HttpContext.Current.Server.MapPath("~/App_Data/ict-courses-bsd.csv");

                // Create a stream reader object, to read from the file system
                StreamReader sr = File.OpenText(path);

                // Create the CsvHelper object
                var csv = new CsvReader(sr);

                // Configure the mapping classes (if it exists)
                csv.Configuration.RegisterClassMap<CourseMap>();

                // Go through the data file
                while (csv.Read())
                {
                    // Read one line in the source file into a new object
                    CourseAdd qb = csv.GetRecord<CourseAdd>();

                    // Add the new object to the data store
                    ds.Courses.Add(Mapper.Map<Course>(qb));
                }

                ds.SaveChanges();

                // Clean up
                sr.Close();
                sr = null;
            }
        }
    }
}