#ifndef _PACKET_H
#define _PACKET_H

class Packet {
private:
	unsigned int header;
	unsigned char *contents;
	unsigned int tail;
public:
	Packet();
	~Packet();
	void SetInfo();
	void PrintInfo();
	int Connect(SOCKET &, char *, int);
	void SendPkt(SOCKET &);
	void ReceivePkt(SOCKET &);
	void Send(SOCKET &);
	void Receive(SOCKET &);
	void CloseSocket(SOCKET &);
	void WinsockExit();
};

#endif