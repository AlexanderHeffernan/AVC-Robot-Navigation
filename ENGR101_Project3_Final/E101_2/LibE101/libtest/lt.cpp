#include <iostream>
#include "E101.h"

using namespace std;

int main()
{
  int err;
  cout<<" Hello"<<endl;
  err = init(0);
  cout<<"After init() error="<<err<<endl;
  
  int count = 0;
  open_screen_stream();
  while(count < 500)
  {
//	 set_motors(1,31);
//	 set_motors(2,38);
	 //set_motors(4,44);
	 set_motors(1,31);
     set_motors(2,31);
     set_motors(3,31);
	 set_motors(4,31);
     set_motors(5,31);
	 hardware_exchange();
	 take_picture();
	 update_screen();
	 sleep1(1000);
	 set_motors(1,48);
     set_motors(2,48);
     set_motors(3,48);
	 set_motors(4,48);
     set_motors(5,48);
	 hardware_exchange();
	 sleep1(1000);
	 set_motors(1,61);
     set_motors(2,61);
     set_motors(3,61);
	 set_motors(4,61);
     set_motors(5,61);
	 hardware_exchange();
	 sleep1(1000);
	 
	 //char fname[5]={'r','r','r','r','r'};
	 //save_picture(fname);
	 //display_picture(0,200000);
	 	
	 //sleep1(1,200); 
         std::cout<<count<<std::endl;
       count++;
    }
    //save_picture("file1");
    close_screen_stream();
    stoph();
	
	return 0;
}
