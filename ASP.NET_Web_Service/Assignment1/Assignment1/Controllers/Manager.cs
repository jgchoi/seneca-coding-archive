using Assignment1.Models;
using AutoMapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Assignment1.Controllers
{
    public class Manager
    {
        private ApplicationDbContext ds = new ApplicationDbContext();

        public IEnumerable<SmartphoneBase> SmartphoneGetAll()
        {
            return Mapper.Map<IEnumerable<SmartphoneBase>>(ds.Smartphones);
        }

        public SmartphoneBase SmartphoneGetById(int id)
        {
            // Attempt to fetch the object
            var o = ds.Smartphones.Find(id);

            // Return the result, or null if not found
            return (o == null) ? null : Mapper.Map<SmartphoneBase>(o);
        }

        public SmartphoneBase SmartphoneAdd(SmartphoneAdd newItem)
        {
            // Attempt to add the new item
            // Notice how we map the incoming data to the design model object
            var addedItem = ds.Smartphones.Add(Mapper.Map<Smartphone>(newItem));
            ds.SaveChanges();

            // If successful, return the added item, mapped to a view model object
            return (addedItem == null) ? null : Mapper.Map<SmartphoneBase>(addedItem);
        }

    }


}