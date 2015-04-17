#ifndef _PKT_DEF_H_
#define _PKT_DEF_H_

#include <windows.networking.sockets.h>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")

//Define keywords
#define DRIVE 15
#define STATUS 5
#define SLEEP 0
#define BUFFER_SIZE 128

//ENum for Command return type
enum CmdReturn { EXIT, STATUS_CMD, SLEEP_CMD, SLEEP_EXIT_CMD, DRIVE_CMD };

//#############################################################################
//Packet Header Structure
struct PacketHeader
{
	unsigned char PacketId;
	unsigned char CmdListSize;
};

//#############################################################################
//Packet Body - Drive command structure
struct DriveCmd
{
	unsigned char Direction;
	unsigned char Duration;
};

//#############################################################################
//Packet Definition & member functions for operation
class PktDef
{
private:
	PacketHeader Header;
	DriveCmd * DriveCmdList;
	unsigned char Parity;

public:
	//Constructor
	PktDef();
	~PktDef();

	//Socket setup
	int Listen(SOCKET &, char *, int);
	int Accept(SOCKET &, SOCKET &);

	//Packet manage
	CmdReturn Command();
	void DisplayPkt();
	int GetParity(unsigned char []);

	//Data communication
	void ReceivePkt(SOCKET &);
	void SendPkt(SOCKET &);

	//Closing
	void CloseSocket(SOCKET &);
	void WinsockExit();
};

#endif