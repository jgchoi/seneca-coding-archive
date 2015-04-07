using BTI_A1.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace BTI_A1.Controllers
{
    public class FollowUpEditForm
    {
        [HiddenInput]
        public int Id { get; set; }

        [Required, StringLength(50, MinimumLength = 5)]
        public string Title { get; set; }

        [Required, StringLength(1000, MinimumLength = 10)]
        public string Description { get; set; }
    }

    public class FollowUpEdit
    {
        [HiddenInput]
        public int Id { get; set; }

        [Required, StringLength(50, MinimumLength = 5)]
        public string Title { get; set; }

        [Required, StringLength(1000, MinimumLength = 10)]
        public string Description { get; set; }
    }


    public class FollowUpAddForm
    {
        [DataType(DataType.DateTime)]
        public DateTime Timestamp { get; set; }


        [Required, StringLength(50, MinimumLength = 5)]
        public string Title { get; set; }

        [Required, StringLength(1000, MinimumLength = 10)]
        public string Description { get; set; }

        [Required, Display(Name="Suggestion Title")]
        public SelectList SuggestionId { get; set; }

        //Constructor
        public FollowUpAddForm()
        {
            Timestamp = DateTime.Now;
        }
    }

    public class FollowUpAdd
    { 

        [DataType(DataType.DateTime),Display(Name="Posted On")]
        public DateTime Timestamp { get; set; }


        [Required, StringLength(50, MinimumLength = 5)]
        public string Title { get; set; }

        [Required, StringLength(1000, MinimumLength = 10)]
        public string Description { get; set; }
        public byte[] Attachment { get; set; }
        public string ContentType { get; set; }

        [Required, Display(Name="Suggestion title")]
        public int SuggestionId { get; set; }

        public HttpPostedFileBase AttachmentUpload { get; set; }

        //Constructor
        public FollowUpAdd()
        {
            Timestamp = DateTime.Now;
        }
    
    }

    public class FollowUpBase : FollowUpAdd
    {
        public int Id { get; set; }
    }

    public class FollowUpBaseWithSuggestion : FollowUpBase
    {
        public Suggestion Suggestion { get; set; }


    }
    public class FollowUpBaseWithSuggestionAndImage : FollowUpBaseWithSuggestion
    {

        [Display(Name = "Attached Image")]
        new public byte[] Attachment { get; set; }
        new public string ContentType { get; set; }

    }

}