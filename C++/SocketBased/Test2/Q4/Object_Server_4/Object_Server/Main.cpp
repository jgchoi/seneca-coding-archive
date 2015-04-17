#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

#include<iostream>;
#include <string>;
#include "Class.h";
using namespace std;

int main() {

	SOCKET ServerSocket, ConnectionSocket;
	char IP[128] = { "127.0.0.1" };
	int Port = 27000;

	Packet PacketObj;

	if (PacketObj.Listen(ServerSocket, IP, Port) != 0) {
		if (PacketObj.Accept(ServerSocket, ConnectionSocket) != 0) {

			PacketObj.ReceivePkt(ConnectionSocket);
			PacketObj.PrintInfo();
			PacketObj.Send(ConnectionSocket);

			PacketObj.CloseSocket(ConnectionSocket);
			PacketObj.CloseSocket(ServerSocket);
			PacketObj.WinsockExit();
		}
	}
	else {
		cout << " Connection Error - Exiting..." << endl;
	}

	return 0;

}
