#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
using namespace std;

struct packet_str {
	unsigned char header;
	unsigned int *body;
	unsigned char tail;
};

int main() {

	sockaddr_in SvrAddr;
	SOCKET WelcomeSocket, ConnectionSocket;
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	//if ((WelcomeSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		//return 0;

	WelcomeSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (WelcomeSocket == INVALID_SOCKET) {
		WSACleanup();
		return 0;
	}

	SvrAddr.sin_family = AF_INET;
	SvrAddr.sin_addr.s_addr = INADDR_ANY;
	SvrAddr.sin_port = htons(27000);

	if (bind(WelcomeSocket, (struct sockaddr *)&SvrAddr,
		sizeof(SvrAddr)) == SOCKET_ERROR)
	{
		closesocket(WelcomeSocket);
		WSACleanup();
		return 0;
	}

/*	if (listen(WelcomeSocket, 1) == SOCKET_ERROR){
		closesocket(WelcomeSocket);
		return 0;
	}*/

	cout << "Waiting for client connection" << endl;
	ConnectionSocket = SOCKET_ERROR;

	char RxBuffer[128];
	while (1) {
		/*
		if ((ConnectionSocket = accept(WelcomeSocket, NULL, NULL)) == SOCKET_ERROR) {
		return 0;
		}
		else {
		*/
		//int n = recv(ConnectionSocket, RxBuffer, sizeof(RxBuffer), 0);
		struct sockaddr_in CltAddr;
		int addr_len;
		addr_len = sizeof(CltAddr);

		int n = recvfrom(WelcomeSocket, RxBuffer, sizeof(RxBuffer), 0,
			(struct sockaddr *) &CltAddr, &addr_len);

		packet_str packet_rx;
		packet_rx.header = RxBuffer[0];
		// creates an integer pointer starting at RxBuffer[1]
		int *aux_int = (int *)&RxBuffer[1];
		packet_rx.body = new unsigned int[packet_rx.header];
		for (int i = 0; i < packet_rx.header; i++)
			packet_rx.body[i] = *aux_int++;  //gets the value in aux_int and increments
		//saves the final item in RxBuffer into packet_rx.tail
		packet_rx.tail = RxBuffer[1 + sizeof(int)*packet_rx.header];

		cout << "header: " << (int)packet_rx.header << endl;
		for (int i = 0; i < packet_rx.header; i++)
			cout << "element " << i << ": " << (int)packet_rx.body[i] << endl;
		cout << "tail" << (int)packet_rx.tail << endl;
		//closesocket(ConnectionSocket);
		//}
	}
	closesocket(WelcomeSocket);
	WSACleanup();

	return 0;
}