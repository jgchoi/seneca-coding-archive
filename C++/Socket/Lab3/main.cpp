#include <iostream>
#include "Class.h"
using namespace std;
int main(int argc, char *argv[]) {
	if (argc < 6) {
		cout << "Invalid number of arguments" << endl;
		return -1;
	}
	Data DataPkt;
	DataPkt.SetID(argv[1]);
	DataPkt.SetCount(argv[2]);
	DataPkt.SetFlag1(argv[3]);
	DataPkt.SetFlag2(argv[4]);
	DataPkt.SetFlag3(argv[5]);
	DataPkt.SetFlag4(argv[6]);
	DataPkt.Display();
	DisplayHex(DataPkt);
	return 0;
}