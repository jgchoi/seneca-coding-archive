using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace Assignment6.Controllers
{
    public class ArtistsController : ApiController
    {
        private Manager m = new Manager();

        /// <summary>
        /// All Artists information with number of albums!
        /// </summary>
        /// <returns>AlbumBase</returns>
        // GET: api/Artists
        public IHttpActionResult Get()
        {
            var c = m.ArtistGetAll();

            var result = new ArtistsLinked(Mapper.Map<IEnumerable<ArtistWithLink>>(c));

            return Ok(result);
        }

        /// <summary>
        /// Specific Artist information with reference to albums
        /// </summary>
        /// <param name="id">ArtistId</param>
        /// <returns>ArtistWithAlbum</returns>
        // GET: api/Artists/5
        public IHttpActionResult Get(int? id)
        {
            // Determine whether we can continue
            if (!id.HasValue) { return NotFound(); }

            // Fetch the object, so that we can inspect its value
            var o = m.ArtistGetById(id.Value);

            if (o == null)
            {
                return NotFound();
            }
            else
            {
                // Create a hypermedia representation
                ArtistLinked result = new ArtistLinked
                    (Mapper.Map<ArtistWithLink>(o));

                foreach (var item in result.Item.Albums)
                {
                    // Add album link
                    item.Link = new Link
                    {
                        Href = "api/albums/" + item.AlbumId,
                        Method = "GET",
                        Rel = "item"
                    };
                }

                return Ok(result);
            }
        }

    }
}
