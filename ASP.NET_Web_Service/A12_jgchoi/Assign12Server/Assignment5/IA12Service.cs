using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace Assignment5
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "IA12Service" in both code and config file together.
    [ServiceContract]
    public interface IA12Service
    {


        [OperationContract]
        IEnumerable<Controllers.CustomerWithData> CustomerGetAll();

        [OperationContract]
        Controllers.CustomerWithData CustomerById(int? id);

        [OperationContract]
        Controllers.CustomerWithData CustomerAdd(Controllers.CustomerAdd newItem);
        [OperationContract]

        Controllers.CustomerWithData CustomerEditAddress(Controllers.CustomerEditAddress editedItem);
        [OperationContract]
        void CustomerSetSupportRep(Controllers.CustomerSupportRep item);

        [OperationContract]
        IEnumerable<Controllers.InvoiceWithData> InvoiceGetAll();

    }
}
