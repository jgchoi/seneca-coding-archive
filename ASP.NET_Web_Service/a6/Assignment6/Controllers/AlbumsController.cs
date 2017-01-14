using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace Assignment6.Controllers
{
    public class AlbumsController : ApiController
    {
        private Manager m = new Manager();

        // GET: api/Albums
        public IHttpActionResult Get()
        {
            var c = m.AlbumGetAll();

            var result = new AlbumsLinked(Mapper.Map<IEnumerable<AlbumWithLink>>(c));

            return Ok(result);
        }

        /// <summary>
        /// Specific Album information with reference to tracks and atritst name. If accept image, return image if possible
        /// </summary>
        /// <param name="id">AlbumId</param>
        /// <returns>AlbumWithTrack or img</returns>
        // GET: api/Albums/5
        public IHttpActionResult Get(int? id)
        {
            // Determine whether we can continue
            if (!id.HasValue) { return NotFound(); }

            var imageHeader = Request.Headers.Accept
                .SingleOrDefault(a => a.MediaType.ToLower().StartsWith("image/"));

            // Fetch the object, so that we can inspect its value
            var o = m.AlbumGetById(id.Value);

            if (imageHeader == null)
            {
                if (o == null)
                {
                    return NotFound();
                }
                else
                {
                    // Create a hypermedia representation
                    AlbumLinked result = new AlbumLinked
                        (Mapper.Map<AlbumWithLink>(o));

                    foreach (var item in result.Item.Tracks)
                    {
                        // Add album link
                        item.Link = new Link
                        {
                            Href = "api/tracks/" + item.TrackId,
                            Method = "GET",
                            Rel = "item"
                        };
                    }

                    return Ok(result);
                }
            }
            else
            {
                // Special processing for an image result

                // Confirm that a media item exists
                if (o.PhotoLength > 0)
                {
                    // Return the result, using the custom media formatter
                    return Ok(o.Photo);
                }
                else
                {
                    // Otherwise, return "not found"
                    // Yes, this is correct. Read the RFC: https://tools.ietf.org/html/rfc7231#section-6.5.4
                    return NotFound();
                }
            }

           
        }


        /// <summary>
        /// Set photo for album
        /// </summary>
        /// <param name="id">Album ID</param>
        /// <param name="photo">Photo data</param>
        /// <returns></returns>
        // PUT: api/Albums/5/setphoto
        // Notice the use of the [HttpPut] attribute, which is an alternative to the method name starting with "Put..."
        [Route("api/albums/{id}/setphoto")]
        [HttpPut]
        public IHttpActionResult AlbumPhoto(int id, [FromBody]byte[] photo)
        {
            // Get the Content-Type header from the request
            var contentType = Request.Content.Headers.ContentType.MediaType;

            // Attempt to save
            if (m.AlbumSetPhoto(id, contentType, photo))
            {
                // By convention, we have decided to return HTTP 204
                // It's a 'success' code, but there's no content for a 'command' task
                return StatusCode(HttpStatusCode.NoContent);
            }
            else
            {
                // Uh oh, some error happened, so tell the requestor
                return BadRequest("Unable to set the photo");
            }
        }
    }
}
