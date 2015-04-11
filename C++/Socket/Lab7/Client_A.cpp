#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
using namespace std;

struct packet_str {
	unsigned char header;
	unsigned int *body;
	unsigned char tail;
};

int main(){

	packet_str packet, packet2;

	unsigned char *ptr, *aux_ptr;
	int *aux_int;
	int size, aux;

	cout << "What is the header value?";
	cin >> size;

	//defines packet with dynamic component
	packet.header = (unsigned char)size;
	packet.body = new unsigned int[size];
	for (int i = 0; i < size; i++) {
		cout << "What is element " << i << " value?" << endl;
		cin >> aux;
		packet.body[i] = (unsigned char)aux;
	}
	cout << "What is the tail value?";
	packet.tail = 4;

	//saves this packet in an dynamically allocated 
	//unsigned char pointer array
	ptr = new unsigned char[2 + size*sizeof(int)];
	ptr[0] = packet.header;
	for (int i = 0; i < size; i++){
		//saves the first byte of packet.body[i] into aux_ptr
		aux_ptr = (unsigned char *)&packet.body[i];
		for (int k = 0; k < sizeof(int); k++)
			ptr[1 + i*sizeof(int) + k] = *(aux_ptr++);
	}
	ptr[1 + sizeof(int)*size] = packet.tail;

	struct sockaddr_in SvrAddr;
	SOCKET ClientSocket;
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	//if ((ClientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		//return 0;

	ClientSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (ClientSocket == INVALID_SOCKET) {
		return 0;
	}


	SvrAddr.sin_family = AF_INET;
	SvrAddr.sin_port = htons(27000);
	SvrAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

/*	if ((connect(ClientSocket, (struct sockaddr *)&SvrAddr, sizeof(SvrAddr)))
		== SOCKET_ERROR) {
		closesocket(ClientSocket);
		WSACleanup();
		return 0;
	}*/

	//send(ClientSocket, (char *)ptr, size*sizeof(int) + 2, 0);

	sendto(ClientSocket, (char *) ptr, size*sizeof(int)+2, 0,
		(struct sockaddr *)&SvrAddr, sizeof(SvrAddr));

	closesocket(ClientSocket);
	WSACleanup();

	return 0;
}