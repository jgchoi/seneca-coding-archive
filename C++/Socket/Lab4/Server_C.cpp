#include <windows.networking.sockets.h>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")
using namespace std;
void main()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return;
	SOCKET ServerSocket;
	ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ServerSocket == INVALID_SOCKET) {
		WSACleanup();
		return;
	}
	struct sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;
	SvrAddr.sin_addr.s_addr = INADDR_ANY;
	SvrAddr.sin_port = htons(35000);
	if (bind(ServerSocket, (struct sockaddr *)&SvrAddr, sizeof(SvrAddr)) ==
		SOCKET_ERROR)
	{
		closesocket(ServerSocket);
		WSACleanup();
		return;
	}
	if (listen(ServerSocket, 1) == SOCKET_ERROR) {
		closesocket(ServerSocket);
		WSACleanup();
		return;
	}
	cout << "Waiting for client connection\n" << endl;
	SOCKET ConnectionSocket;
	ConnectionSocket = SOCKET_ERROR;
	if ((ConnectionSocket = accept(ServerSocket, NULL, NULL)) == SOCKET_ERROR) {
		closesocket(ServerSocket);
		WSACleanup();
		return;
	}

	closesocket(ServerSocket);


	cout << "Connection Established" << endl;

	char RxBuffer[128] = {};
	char TxBuffer[20] = { "Received Message" };
	while (true){
		recv(ConnectionSocket, RxBuffer, sizeof(RxBuffer), 0);
		cout << "Msg Rx: " << RxBuffer << endl;
		send(ConnectionSocket, TxBuffer, sizeof(TxBuffer), 0);

		if (RxBuffer[0] == 'q' && RxBuffer[1] == '\0')
			break;

	}

	closesocket(ConnectionSocket);
	WSACleanup();
}