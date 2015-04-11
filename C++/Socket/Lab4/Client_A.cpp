#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")
#include <iostream>
using namespace std;
void main()
{
	WSADATA wsaData;
	if ((WSAStartup(MAKEWORD(2,2) , &wsaData)) != 0) {
		return;
	}
	SOCKET ClientSocket;
	ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ClientSocket == INVALID_SOCKET) {
		WSACleanup();
		return;
	}
	struct sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;
	SvrAddr.sin_port = htons(35000);
	SvrAddr.sin_addr.s_addr = inet_addr("127.0.0.1");;
		if ((connect(ClientSocket, (struct sockaddr *)&SvrAddr, sizeof(SvrAddr))) ==
			SOCKET_ERROR) {
			closesocket(ClientSocket);
			WSACleanup();
			return;
		}
	char TxBuffer[128] = {};
	cout << "Enter a String to transmit" << endl;
	cin >> TxBuffer;
	send(ClientSocket, TxBuffer, sizeof(TxBuffer), 0);
	closesocket(ClientSocket);
	WSACleanup();
}
