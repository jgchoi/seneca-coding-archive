#include <iostream>
#include "Class.h"
using namespace std;
int main() {
	protocol protocol_obj(3);
	protocol_obj.display_header();
	set_data_items(protocol_obj);
	display_data_items(protocol_obj);
	return 0;
}