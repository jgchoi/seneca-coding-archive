#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

#include<iostream>;
#include <string>;
#include "Class.h";
using namespace std;

int main() {

	SOCKET ClientSocket;
	char IP[128] = { "127.0.0.1" };
	int Port = 27000;

	Packet PacketObj;
	PacketObj.SetInfo();

	if (PacketObj.Connect(ClientSocket, IP, Port) != 0) {

		PacketObj.SendPkt(ClientSocket);
		PacketObj.Receive(ClientSocket);

		PacketObj.CloseSocket(ClientSocket);
		PacketObj.WinsockExit();
	}
	else {
		cout << " Connection Error - Exiting..." << endl;
	}

	return 0;

}