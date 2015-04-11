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

int main(){

	packet_str packet, packet2;

	unsigned char *ptr, *aux_ptr;
	int *aux_int;
	int size1, aux, size2;

	cout << "What is the header1 value?";
	cin >> size1;

	//defines packet with dynamic component
	packet.header[0] = (unsigned char)size1;
	packet.body1 = new unsigned int[size1];
	for (int i = 0; i < size1; i++) {
		cout << "What is element " << i << " value?" << endl;
		cin >> aux;
		packet.body1[i] = (unsigned char)aux;
	}
	packet.tail = 4;

	cout << "What is the header2 value?";
	cin >> size2;

	//defines packet with dynamic component
	packet.header[1] = (unsigned char)size2;
	packet.body2 = new unsigned int[size2];
	for (int i = 0; i < size2; i++) {
		cout << "What is element " << i << " value?" << endl;
		cin >> aux;
		packet.body2[i] = (unsigned char)aux;
	}
	packet.tail = 4;
	

	//saves this packet in an dynamically allocated 
	//unsigned char pointer array
	ptr = new unsigned char[2 + size1*sizeof(int) + size2*sizeof(int) + 1];
	ptr[0] = packet.header[0];
	ptr[1] = packet.header[1];

	for (int i = 0; i < size1; i++){
		//saves the first byte of packet.body[i] into aux_ptr
		aux_ptr = (unsigned char *)&packet.body1[i];
		for (int k = 0; k < sizeof(int); k++)
			ptr[2 + i*sizeof(int) + k] = *(aux_ptr++);
	}

	for (int i = 0; i < size2; i++){
		//saves the first byte of packet.body[i] into aux_ptr
		aux_ptr = (unsigned char *)&packet.body2[i];
		for (int k = 0; k < sizeof(int); k++)
			ptr[2 + size1*sizeof(int) + i*sizeof(int) + k] = *(aux_ptr++);
	}

	ptr[2 + size1*sizeof(int) + size2*sizeof(int)] = packet.tail;

	struct sockaddr_in SvrAddr;
	SOCKET ClientSocket;
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	if ((ClientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		return 0;

	SvrAddr.sin_family = AF_INET;
	SvrAddr.sin_port = htons(27000);
	SvrAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if ((connect(ClientSocket, (struct sockaddr *)&SvrAddr, sizeof(SvrAddr)))
		== SOCKET_ERROR) {
		closesocket(ClientSocket);
		WSACleanup();
		return 0;
	}

send(ClientSocket, (char *)ptr, 2 + size1*sizeof(int) + size2*sizeof(int) + 1, 0);

	closesocket(ClientSocket);
	WSACleanup();

	return 0;
}