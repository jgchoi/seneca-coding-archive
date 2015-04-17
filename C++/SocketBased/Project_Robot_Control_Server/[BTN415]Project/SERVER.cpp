#include "PKT_DEF.H"
#include <iostream>
#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

using namespace std;

//#############################################################################
//Main
int main() {
	//Connection Setup
	char IP[128] = { "127.0.0.1" };
	int Port = 5000;

	//Local variable
	SOCKET ServerSocket, ConnectionSocket;
	PktDef PktObj;
	CmdReturn cmdReturn; //Command return value

	//IP bind
	if (PktObj.Listen(ServerSocket, IP, Port) != 0)
	{
		//While loop for accepting connection
		while (true)
		{
			if (PktObj.Accept(ServerSocket, ConnectionSocket) != 0)
			{
				//Create command
				cmdReturn = PktObj.Command();

				if (cmdReturn == EXIT) //user request exit
					break;

				PktObj.SendPkt(ConnectionSocket); //If not break, send packet

				if (cmdReturn == SLEEP_EXIT_CMD)
					break;

				if (cmdReturn == STATUS_CMD) //user request status expect reciving data
				{
					PktObj.ReceivePkt(ConnectionSocket); //Reciving & write it into the PktObj object
					PktObj.DisplayPkt(); //Display what's in the packet
				}
				//Disconnect the connection.
				PktObj.CloseSocket(ConnectionSocket);

			} // End of If
			else
			{
				cout << " Connection Error - Accept error... " << endl;
			}
		} //End of while

		//After breaking from the loop, close all connection and exit program	
		PktObj.CloseSocket(ServerSocket);
		PktObj.WinsockExit();
	}
	else
	{
		cout << " Connection Error - Binding error..." << endl;
	}

	return 0;
}