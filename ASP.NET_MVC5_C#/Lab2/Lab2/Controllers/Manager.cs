using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

using System.IO;
using Biggy.Core;
using Biggy.Data.Json;

namespace Lab2.Controllers
{
    public class Manager
    {
        //variables
        private JsonStore<CarFull> store;
        private BiggyList<CarFull> cars;

        //constructor
        public Manager()
        {
            //path
            var localData = HttpContext.Current.Server.MapPath("~/App_Data");

            //Open or create data store
            store = new JsonStore<CarFull>(localData, "lab2", "cars");

            //Assign collection
            cars = new BiggyList<CarFull>(store);
        }

        //public property
        public IEnumerable<CarFull> AllCars
        {
            get { return cars.OrderBy(y => y.Year).AsEnumerable(); }
        }

        //adding method
        public CarFull AddCar(CarAdd newItem)
        {
            //New id
            int newId = (cars.Count > 0) ? newId = cars.Max(id => id.Id) + 1 : 1;

            //new item
            var addedItem = new CarFull
            {
                Id = newId,
                Manufacturer = newItem.Manufacturer,
                Model = newItem.Model,
                MSRP = newItem.MSRP,
                Year = newItem.Year
            };

            //Add new item
            cars.Add(addedItem);

            //return value
            return addedItem;
        }
    }
}