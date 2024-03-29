#include <windows.networking.sockets.h>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")
using namespace std;
void main(int argc, char *argv[])
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return;
	SOCKET ServerSocket;
	ServerSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (ServerSocket == INVALID_SOCKET) {
		WSACleanup();
		return;
	}struct sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;
	SvrAddr.sin_addr.s_addr = INADDR_ANY;
	SvrAddr.sin_port = htons(32000);
	if (bind(ServerSocket, (struct sockaddr *)&SvrAddr, sizeof(SvrAddr)) ==
		SOCKET_ERROR)
	{
		closesocket(ServerSocket);
		WSACleanup();
		return;
	}
	char RxBuffer[128] = {};
	struct sockaddr_in ClientAddr;
	int addr_len;
	addr_len = sizeof(ClientAddr);
	recvfrom(ServerSocket, RxBuffer, sizeof(RxBuffer), 0,
		(struct sockaddr *) &ClientAddr, &addr_len);
	cout << "Msg Rx: " << RxBuffer << endl;
	closesocket(ServerSocket);
	WSACleanup();
}