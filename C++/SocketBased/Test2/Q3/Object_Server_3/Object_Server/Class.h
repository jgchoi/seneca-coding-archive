#ifndef _PACKET_H
#define _PACKET_H
struct body_str {
	unsigned char size;
	unsigned int *contents;
};
class Packet {
private:
	unsigned char header;
	body_str body;
	unsigned char tail;
public:
	Packet();
	~Packet();
	void SetInfo();
	void PrintInfo();
	int Listen(SOCKET &, char *, int);
	int Accept(SOCKET &, SOCKET &);
	void ReceivePkt(SOCKET &);
	void Send(SOCKET &);
	void Receive(SOCKET &);
	void CloseSocket(SOCKET &);
	void WinsockExit();
};

#endif
