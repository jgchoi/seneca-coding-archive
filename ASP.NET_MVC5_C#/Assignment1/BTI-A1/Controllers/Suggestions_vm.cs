using BTI_A1.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace BTI_A1.Controllers
{
    public class SuggestionEditForm
    {
        [HiddenInput]
        public int Id { get; set; }

        [Required, StringLength(50, MinimumLength = 5)]
        public string Title { get; set; }

        [Required, StringLength(1000, MinimumLength = 10)]
        public string Description { get; set; }
 
    }

    public class SuggestionEdit
    {
        [HiddenInput]
        public int Id { get; set; }

        [Required, StringLength(50, MinimumLength = 5)]
        public string Title { get; set; }

        [Required, StringLength(1000, MinimumLength = 10)]
        public string Description { get; set; }
    }
    public class SuggestionAddForm
    {
        //Constructor for Datetime init


        [Required, StringLength(50, MinimumLength = 5)]
        public string Title { get; set; }

        [Required, StringLength(1000, MinimumLength = 10)]
        public string Description { get; set; }


        [Required, Display(Name = "Program")]
        public SelectList ProgramId { get; set; }

        [Required, Display(Name = "Course")]
        public SelectList CourseId { get; set; }
    }

    public class SuggestionAdd
    {
        //Constructor for Datetime init
        public SuggestionAdd()
        {
            Timestamp = DateTime.Now;
        }

        [DataType(DataType.DateTime), Display(Name="Posted On")]
        public DateTime Timestamp { get; set; }


        [Required, StringLength(50, MinimumLength = 5)]
        public string Title { get; set; }

        [Required, StringLength(1000, MinimumLength = 10)]
        public string Description { get; set; }

        public int ProgramId { get; set; }

        public int CourseId { get; set; }

        public HttpPostedFileBase AttachmentUpload { get; set; }
    }

    public class SuggestionBase : SuggestionAdd
    {
        public int Id { get; set; }
        public string Program { get; set; }
        public string Course { get; set; }
    }

    public class SuggestionBaseWithImage : SuggestionBase
    {
        [Display(Name="Attached Image")]
        public byte[] Attachment { get; set; }
        public string ContentType { get; set; }
    }

    public class SuggestionBaseWithFollowUps:SuggestionBaseWithImage
    {
        [Display(Name="Follow Up Postings")]
        public IEnumerable<FollowUp> FollowUps { get; set; }
    }


    public class SuggestionList
    {
        public int Id { get; set; }

        [Required, StringLength(50, MinimumLength = 5)]
        public string Title { get; set; }


    }
}