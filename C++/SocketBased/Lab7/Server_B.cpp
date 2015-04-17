#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
using namespace std;

struct packet_str {
	unsigned char header[2];
	unsigned int *body1;
	unsigned int *body2;
	unsigned char tail;
};

int main() {

	sockaddr_in SvrAddr;
	SOCKET WelcomeSocket, ConnectionSocket;
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	if ((WelcomeSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		return 0;

	SvrAddr.sin_family = AF_INET;
	SvrAddr.sin_addr.s_addr = INADDR_ANY;
	SvrAddr.sin_port = htons(27000);

	if ((bind(WelcomeSocket, (struct sockaddr *)&SvrAddr, sizeof(SvrAddr)))
		== SOCKET_ERROR) {
		closesocket(WelcomeSocket);
		WSACleanup();
		return 0;
	}

	if (listen(WelcomeSocket, 1) == SOCKET_ERROR){
		closesocket(WelcomeSocket);
		return 0;
	}

	cout << "Waiting for client connection" << endl;
	ConnectionSocket = SOCKET_ERROR;

	char RxBuffer[128];
	while (1) {
		if ((ConnectionSocket = accept(WelcomeSocket, NULL, NULL)) == SOCKET_ERROR) {
			return 0;
		}
		else {
			int n = recv(ConnectionSocket, RxBuffer, sizeof(RxBuffer), 0);

			packet_str packet_rx;
			packet_rx.header[0] = RxBuffer[0];
			packet_rx.header[1] = RxBuffer[1];

			// creates an integer pointer starting at RxBuffer[1]
			int *aux_int = (int *)&RxBuffer[2];
			packet_rx.body1 = new unsigned int[packet_rx.header[0]];
			for (int i = 0; i < packet_rx.header[0]; i++)
				packet_rx.body1[i] = *aux_int++;  //gets the value in aux_int and increments
			packet_rx.body2 = new unsigned int[packet_rx.header[1]];
			for (int i = 0; i < packet_rx.header[1]; i++)
				packet_rx.body2[i] = *aux_int++;  //gets the value in aux_int and increments


			//saves the final item in RxBuffer into packet_rx.tail
			packet_rx.tail = RxBuffer[2 + sizeof(int)*packet_rx.header[0] + sizeof(int)*packet_rx.header[1]];

			cout << "header1: " << (int)packet_rx.header[0] << endl;
			cout << "header2: " << (int)packet_rx.header[1] << endl;
			for (int i = 0; i < packet_rx.header[0]; i++)
				cout << "element " << i << ": " << (int)packet_rx.body1[i] << endl;
			for (int i = 0; i < packet_rx.header[1]; i++)
				cout << "element " << i << ": " << (int)packet_rx.body2[i] << endl;
			cout << "tail" << (int)packet_rx.tail << endl;
			closesocket(ConnectionSocket);
		}
	}
	closesocket(WelcomeSocket);
	WSACleanup();

	return 0;
}