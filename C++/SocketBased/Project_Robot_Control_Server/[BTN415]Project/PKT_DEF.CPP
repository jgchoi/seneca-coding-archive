#include "PKT_DEF.H"

using namespace std;

//Default Constructor
// Set member variables to safe state
PktDef::PktDef() {
	Header.PacketId = 0;
	Header.CmdListSize = 0;
	DriveCmdList = nullptr;
	Parity = 0;
}


//Default Desctructor
// Dealloc dyanimically allocated variables
PktDef::~PktDef() {
	if (DriveCmdList != nullptr)
		delete[] DriveCmdList;
	DriveCmdList = nullptr;
}

//Command
// Create command using user input, return command type choosen
CmdReturn PktDef::Command()
{
	//Variables
	int ui; // user input

	//PacketId Drive Status or Sleep
	cout << "### Creating New Command ###" << endl;
	cout << "Type: 1-Drive, 2-Status, 3-Sleep, 0-Exit" << endl;
	cout << " 1) Type: ";
	cin >> ui;

	if (ui == 0)//If exit requested
		return EXIT;

	if (ui != 1)//status or sleep (either 2,3)
	{
		Header.CmdListSize = 0;
		Header.PacketId = ui == 2 ? STATUS : SLEEP; //set pkId 5 for status 0 for sleep

		//If sleep, ask user to terminate the server as well
		if (ui == 2)
		{
			return STATUS_CMD;
		}
		else //Sleep requested, ask user to terminate the program
		{
			char ui; // Temp vari. for char input

			cout << "Sleep command request. Terminate server as well? (Y/N): ";
			cin >> ui;
			return ui == 'N' ? SLEEP_CMD : SLEEP_EXIT_CMD;
		}
	}
	else //only possible case is 1
	{
		Header.PacketId = DRIVE;

		//CMD size?
		cout << " 2) Cmd Size: ";
		cin >> ui;

		//Assuming it's 1~10 

		//Dealloc if exist
		if (DriveCmdList != nullptr)
			delete[] DriveCmdList;
		DriveCmdList = nullptr;

		//Allocation
		DriveCmdList = new DriveCmd[ui];

		//Header size
		Header.CmdListSize = ui;

		//Taking command
		for (int i = 0; i < Header.CmdListSize; i++)
		{
			cout << "Drive Command 1-F, 2-B, 3-L, 4-R" << endl;
			cout << " 3-1) Direction: ";
			cin >> ui;

			//Assume value is right

			//Set direction
			DriveCmdList[i].Direction = ui;

			cout << " 3-2) Duration: ";
			cin >> ui;

			//Set duration
			DriveCmdList[i].Duration = ui;

		} // End for

		return DRIVE_CMD;
	}//end else

	//If program hit this point, there's an error
	cout << "### Error found during the command creating process ###";
	return EXIT;
}

//Display Packet information received
void PktDef::DisplayPkt() {
	cout << "### Display Packet ###" << endl;
	cout << "Header:" << endl;
	cout << " -PacketId   : " << (int)Header.PacketId << endl;
	cout << " -CmdListSize: " << (int)Header.CmdListSize << endl;
	cout << endl;
	cout << "Body:" << endl;
	for (int i = 0; i < Header.CmdListSize; i++)
	{
		cout << "Command(" << i + 1 << ")" << endl;
		cout << " -Direction: " << (int)DriveCmdList[i].Direction << endl;
		cout << " -Duration : " << (int)DriveCmdList[i].Duration << endl;
	}
	cout << endl;
	cout << "Parity: " << (int)Parity << endl;
}


int PktDef::Listen(SOCKET &ServerSocket, char * IP, int Port) {
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
	SvrAddr.sin_port = htons(Port);
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
	cout << "...Bind to " << IP << " : " << Port << endl;
	return 1;

}

int PktDef::Accept(SOCKET &ServerSocket, SOCKET &ConnectionSocket) {
	cout << "Waiting for client connection..." << endl;

	if ((ConnectionSocket = accept(ServerSocket, NULL, NULL)) == SOCKET_ERROR) {
		closesocket(ServerSocket);
		WSACleanup();
		return 0;
	}

	cout << "...Connection Established" << endl;
	return 1;
}

void PktDef::ReceivePkt(SOCKET &ConnectionSocket){
	//Empty Buffer
	char RxBuffer[BUFFER_SIZE] = {};
	int pos = 0;
	//Wait for the signal
	if (recv(ConnectionSocket, RxBuffer, sizeof(RxBuffer), 0) > 0)
	{

		//Header
		Header.PacketId = RxBuffer[pos++];
		//Header.CmdListSize = RxBuffer[pos++];
		Header.CmdListSize = 5; // Robot sends 10 command but only 5 commands are recived, 5 are hard coded to fix the problem
		pos++; // Manual position increment

		//Clear body
		//Dealloc if exist
		if (DriveCmdList != nullptr)
			delete[] DriveCmdList;
		DriveCmdList = nullptr;

		//Allocation
		DriveCmdList = new DriveCmd[Header.CmdListSize];

		//Write Body
		for (int i = 0; i < Header.CmdListSize; i++) // Issue with buffer from the robot..
		{
			DriveCmdList[i].Direction = RxBuffer[pos++];
			DriveCmdList[i].Duration = RxBuffer[pos++];
		}

		//Parity
		Parity = RxBuffer[pos];
	}
}

void PktDef::SendPkt(SOCKET &ConnectionSocket){
	int pos = 0; //Current position

	unsigned char TxBuffer[BUFFER_SIZE] = {}; //Safe state

	//header
	TxBuffer[pos++] = Header.PacketId; //pos 1
	TxBuffer[pos++] = Header.CmdListSize; //pos2

	//Body
	for (int i = 0; i < Header.CmdListSize; i++)
	{
		TxBuffer[pos++] = DriveCmdList[i].Direction;
		TxBuffer[pos++] = DriveCmdList[i].Duration;
	}

	//Parity
	TxBuffer[pos] = GetParity(TxBuffer);
	unsigned int bufferSize = 2 + 2 * (Header.CmdListSize) + 1; // Header + cmdsize * 2 + parity
	send(ConnectionSocket, (char *)TxBuffer, bufferSize, 0);
}

int PktDef::GetParity(unsigned char buffer[])
{
	Parity = 0;

	for (int i = 0; i < BUFFER_SIZE; i++) //For entire buffer
	{
		unsigned char c = (int)buffer[i]; // char 

		for (int j = 0; j < (sizeof(unsigned char) * 8); j++)//for size of bits in unsigned char (8)
		{
			//go each byte and if 1 increase Parity by 1
			if (((c >> j) & 1) == 1)
				Parity++;
		}
	}

	return Parity;
}

void PktDef::CloseSocket(SOCKET &Socket){
	closesocket(Socket);
}

void PktDef::WinsockExit(){
	WSACleanup();
}


