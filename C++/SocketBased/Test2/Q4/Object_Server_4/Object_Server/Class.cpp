#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

#include "Class.h"
#include <iostream>

using namespace std;

Packet::Packet() {
	header = 1;
	contents = new unsigned char[header];
	contents[0] = 0;
	tail = 0;
}

Packet::~Packet() {
	delete[] contents;
	contents = nullptr;
}

void Packet::SetInfo() {

	delete[] contents;
	contents = nullptr;

	int AuxInt;
	cout << "What is the contents size? ";
	cin >> AuxInt;
	header = AuxInt;
	contents = new unsigned char[header];
	for (int i = 0; i < header; i++){
		cout << "Element value: ";
		cin >> AuxInt;
		contents[i] = AuxInt;
	}
	cout << "What is the tail content? ";
	cin >> AuxInt;
	tail = AuxInt;

}

void Packet::PrintInfo() {
	cout << "Header: " << header << endl;
	for (int i = 0; i < header; i++)
		cout << "Content " << i << ": " << (int)contents[i] << ", ";
	cout << endl;
	cout << "Tail: " << tail << endl;
}
int Packet::Listen(SOCKET &ServerSocket, char * IP, int Port) {
	//starts Winsock DLLs   
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	//create server socket
	ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ServerSocket == INVALID_SOCKET) {
		WSACleanup();
		return 0;
	}

	//binds socket to address
	struct sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;
	SvrAddr.sin_addr.s_addr = inet_addr(IP);
	SvrAddr.sin_port = htons(27000);
	if (bind(ServerSocket, (struct sockaddr *)&SvrAddr, sizeof(SvrAddr)) == SOCKET_ERROR)
	{
		closesocket(ServerSocket);
		WSACleanup();
		return 0;
	}

	//listen on a socket
	if (listen(ServerSocket, 1) == SOCKET_ERROR) {
		closesocket(ServerSocket);
		WSACleanup();
		return 0;
	}

	cout << "Waiting for client connection" << endl;

	return 1;

}

int Packet::Accept(SOCKET &ServerSocket, SOCKET &ConnectionSocket) {
	if ((ConnectionSocket = accept(ServerSocket, NULL, NULL)) == SOCKET_ERROR) {
		closesocket(ServerSocket);
		WSACleanup();
		return 0;
	}

	cout << "Connection Established" << endl;
	return 1;
}


void Packet::ReceivePkt(SOCKET &ConnectionSocket){

	char RxBuffer[128] = {};
	if (recv(ConnectionSocket, RxBuffer, sizeof(RxBuffer), 0) > 0) {
		int * aux_int = (int *)RxBuffer;
		header = *aux_int;  //gets the valu

		contents = new unsigned char[header];
		for (int i = 0; i < header; i++)
			contents[i] = RxBuffer[4+i];
		aux_int = (int *)&RxBuffer[4 + header];
		tail = *aux_int;
	}
}

void Packet::Send(SOCKET &ConnectionSocket){

	unsigned char TxBuffer[128] = { "All clear!" };
	send(ConnectionSocket, (char *)TxBuffer, sizeof(TxBuffer), 0);
}

void Packet::Receive(SOCKET &ConnectionSocket){

	char RxBuffer[128] = {};
	if (recv(ConnectionSocket, RxBuffer, sizeof(RxBuffer), 0) > 0) {
		cout << "Received Message: " << RxBuffer << endl;
	}
}

void Packet::CloseSocket(SOCKET &Socket){
	closesocket(Socket);
}


void Packet::WinsockExit(){
	WSACleanup();
}
