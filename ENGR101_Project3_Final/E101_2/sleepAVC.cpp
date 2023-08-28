#include <iostream>
#include "E101.h"

using namespace std;

int main() {
	int err;
	cout<<"Sleeping"<<endl;
	err = init(0);
	cout<<"After init() error="<<err<<endl;
	set_motors(1, 48);
	set_motors(5, 48);
	hardware_exchange();
	return 0;
}


