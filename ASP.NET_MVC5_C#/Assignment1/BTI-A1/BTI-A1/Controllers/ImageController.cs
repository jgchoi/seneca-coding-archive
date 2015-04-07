using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace BTI_A1.Controllers
{
    
    public class ImageController : Controller
    {
        private Manager m = new Manager();

        [Route("image/suggestion/attachment/{id}")]  
        public ActionResult GetSuggestionAttachment(int? id)
        {
            // Determine whether we can continue
            if (!id.HasValue) { return HttpNotFound(); }

            // Fetch the object, so that we can inspect its value
            var fetchedObject = m.GetSuggestionByIdWithImage(id.Value);

            if (fetchedObject == null)
            {
                return HttpNotFound();
            }
            else
            {
                // Return a file content result
                // Set the Content-Type header, and return the photo bytes
                return File(fetchedObject.Attachment, fetchedObject.ContentType);
            }
        }

        [Route("image/followup/attachment/{id}")]
        public ActionResult GetFollowUpAttachment(int? id)
        {
            // Determine whether we can continue
            if (!id.HasValue) { return HttpNotFound(); }

            // Fetch the object, so that we can inspect its value
            var fetchedObject = m.GetFollowUpByIdWithSuggestion(id.Value);

            if (fetchedObject == null)
            {
                return HttpNotFound();
            }
            else
            {
                // Return a file content result
                // Set the Content-Type header, and return the photo bytes
                return File(fetchedObject.Attachment, fetchedObject.ContentType);
            }
        }

        private string GetDefaultFileExtension(string contentType)
        {
            string result;
            Microsoft.Win32.RegistryKey key;
            object value;

            key = Microsoft.Win32.Registry.ClassesRoot
                .OpenSubKey(@"MIME\Database\Content Type\" + contentType, false);
            value = key != null ? key.GetValue("Extension", null) : null;
            result = value != null ? value.ToString() : string.Empty;

            return result;
        }

    }

}