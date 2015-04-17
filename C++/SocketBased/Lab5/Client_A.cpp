#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")
#include <iostream>
using namespace std;
void main()
{
	WSADATA wsaData;
	if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
		return;
	}
	SOCKET ClientSocket;
	ClientSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (ClientSocket == INVALID_SOCKET) {
		WSACleanup();
		return;
	}
	struct sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;       //Address family type internet
	SvrAddr.sin_port = htons(32000);      //port (host to network conversion)
	SvrAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //IP address
	char TxBuffer[128] = {};
		cout << "Enter a String to transmit" << endl;
		cin >> TxBuffer;
		sendto(ClientSocket, TxBuffer, sizeof(TxBuffer), 0,
		(struct sockaddr *)&SvrAddr, sizeof(SvrAddr));
	closesocket(ClientSocket);
	WSACleanup();
}