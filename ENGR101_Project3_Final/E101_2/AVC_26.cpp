#include <iostream>
#include "E101.h"

using namespace std;

void motors(int v_left,int v_right){
	set_motors(1, v_left);
	set_motors(5, v_right);
	hardware_exchange();
}

void camMotorToggle(bool up){
	if(up) {
		set_motors(3, 65);
		hardware_exchange();
	}else {
		set_motors(3, 30);
		hardware_exchange();
	}
}

void q4()
{
	cout<<"Quadrant 4 chosen"<<endl;
	camMotorToggle(true); 
	motors(48, 48);
	bool redDetected = false;
	bool redFinished = false;
	while(redFinished != true) {
		take_picture();
		update_screen();
		double colourRatio = 1.5;
		int minRedLevel = 50;
		int redPixels = 0;
		int error = 0;
		for(int col = 0; col < 320; col++) {
			for(int row = 0; row < 240; row++) {
				double alpha = (double)get_pixel(row, col, 3);	
				double red = (double)get_pixel(row, col, 0);
				double green = (double)get_pixel(row, col, 1);
				double blue = (double)get_pixel(row, col, 2);		

				if(alpha > 25 && red > colourRatio * green && red > colourRatio * blue) {
					redPixels++;
					error = error + col-160;
				}
			}
		}
		cout<<redPixels<<endl;
		if(redPixels > 55000) {
			redFinished = true;
		}
		else if(redPixels > minRedLevel) {
			redDetected = true;
		}
		else {
			redDetected = false;
		}

		if(redDetected != true) {
			motors(50, 50);	
			cout<<"SPIN RED 1"<<endl;
		}
		if(redDetected == true) {
			if(error > 5000){
				motors(53, 48);
				cout<<"Tilt right"<<endl;
			}
			else if(error < -5000){
				motors(48, 43);
				cout<<"Title left"<<endl;
			}
			else {
				motors(54, 41);
				cout<<"Straight ahead"<<endl;
			}
		}
		sleep1(100);
	}
	motors(48, 48);
	sleep1(1000);
	motors(43, 53);
	sleep1(1000);
	bool greenDetected = false;
	bool greenFinished = false;
	while(greenFinished != true) {
		take_picture();
		update_screen();
		double colourRatio = 1.5;
		int minGreenLevel = 50;
		int greenPixels = 0;
		int error = 0;
		for(int col = 0; col < 320; col++) {
			for(int row = 0; row < 240; row++) {
				double alpha = (double)get_pixel(row, col, 3);
				double red = (double)get_pixel(row, col, 0);
				double green = (double)get_pixel(row, col, 1);
				double blue = (double)get_pixel(row, col, 2);
				
				if(alpha > 25 && green > colourRatio * red && green > colourRatio * blue) {
					greenPixels++;
					error = error + col - 160;
				}
			}
		}
		cout<<greenPixels<<endl;
		if(greenPixels > 40000) {
			greenFinished = true;
		} else if(greenPixels > minGreenLevel) {
			greenDetected = true;
		}
		else {
			greenDetected = false;
		}
		
		if(greenDetected != true) {
			motors(46, 46);
			cout<<"SPIN FINDING GREEN"<<endl;
		}
		else {
			if(error > 5000) {
				motors(53, 48);
				cout<<"Tilt right"<<endl;
			}
			else if(error < -5000) {
				motors(48, 43);
				cout<<"Titlt left"<<endl;
			}
			else {
				motors(54, 41);
				cout<<"Straight"<<endl;
			}
		}
		sleep1(100);
	}
	motors(48, 48);
	sleep1(1000);
	motors(43, 53);
	sleep1(1000);
	bool blueDetected = false;
	bool blueFinished = false;
	while(blueFinished != true) {
		take_picture();
		update_screen();
		double colourRatio = 1.5;
		int minBlueLevel = 50;
		int bluePixels = 0;
		int error = 0;
		for(int col = 0; col < 320; col++) {
			for(int row = 0; row < 240; row++) {
				double alpha = (double)get_pixel(row, col, 3);
				double red = (double)get_pixel(row, col, 0);
				double green = (double)get_pixel(row, col, 1);
				double blue = (double)get_pixel(row, col, 2);
				
				if(alpha > 25 && blue > colourRatio * red && blue > colourRatio * green) {
					bluePixels++;
					error = error + col - 160;
				}
			}
		}
		cout<<bluePixels<<endl;
		if(bluePixels > 40000) {
			blueFinished = true;
		} 
		else if(bluePixels > minBlueLevel) {
			blueDetected = true;
		}
		else {
			blueDetected = false;
		}
		
		if(blueDetected != true) {
			motors(50, 50);
			cout<<"SPIN FINDING BLUE"<<endl;
		}
		else {
			if(error > 5000) {
				motors(53, 48);
				cout<<"Tilt right"<<endl;
			}
			else if(error < -5000) {
				motors(48, 43);
				cout<<"Tilt left"<<endl;
			}
			else {
				motors(54, 41);
				cout<<"Straight ahead"<<endl;
			}
		}
		sleep1(100);
	}
	motors(48, 48);
	sleep1(1000);
	motors(43, 53);
	sleep1(1000);
	
	redDetected = false;
	redFinished = false;
	bool redClose = false;
	while(redFinished != true) {
		take_picture();
		update_screen();
		double colourRatio = 1.5;
		int minRedLevel = 50;
		int redPixels = 0;
		int error = 0;
		for(int col = 0; col < 320; col++) {
			for(int row = 0; row < 240; row++) {
				double alpha = (double)get_pixel(row, col, 3);
				double red = (double)get_pixel(row, col, 0);
				double green = (double)get_pixel(row, col, 1);
				double blue = (double)get_pixel(row, col, 2);
	
				if(alpha > 25 && red > colourRatio * green && red > colourRatio * blue) {
					redPixels++;
					error = error + col-160;
				}
			}
		}
		cout<<redPixels<<endl;
		if(redClose == false) {
			if(redPixels > 55000) {
				redClose = true;
			}
			else if(redPixels > minRedLevel) {
				redDetected = true;
			}
			else {
				redDetected = false;
			}

			if(redDetected != true) {
				motors(46, 46);
				cout<<"SPIN FINDING RED 2"<<endl;
			}
			else {
				if(error > 5000) {
					motors(53, 48);
					cout<<"Tilt right"<<endl;
				}
				else if(error < -5000) {
					motors(48, 43);
					cout<<"Tilt left"<<endl;
				}
				else {
					motors(54, 41);
					cout<<"Straight ahead"<<endl;
				}
			}
		}
		else {
			if(redPixels > minRedLevel) {
				motors(54, 42);
				cout<<"Pushing"<<endl;
			}
			else {
				redFinished = true;
			}
		}
		sleep1(100);
	}
	motors(48, 48); 
		
}

bool redDetect(int minRPx){ 
	take_picture();
	update_screen();
	int redPixels = 0;
	for(int col=0; col < 320; col++){
		for(int row = 0; row < 240; row++){
			double alpha = (double)get_pixel(row, col, 3);
			double red = (double)get_pixel(row, col, 0);
			double green = (double)get_pixel(row, col, 1);
			double blue = (double)get_pixel(row, col, 2);
			if (alpha > 25 && red > 1.5 * green && red > 1.5 * blue){
				redPixels++;
			}
		}
	}
	cout<<"RED PIX: "<<redPixels<<endl;
	if (redPixels > minRPx){
		return true;
	}
	else {
		return false;
	}
} 

//detect turn
bool turnDetect(double errorL, double errorR, bool pathL, bool pathR, bool pathT){
	if((errorL > -50 && pathL) || (errorR > -50 && pathR && !pathT)){return true;}
	return false;
}

//turning thing
bool lookForTop(){
	take_picture();
	update_screen();
	for(int col = 155; col < 165; col++){
		int lum = (int)get_pixel(10, col, 3);
		if (lum <100){return true;}
		else{return false;}
	}
	return false;
}

void straight(double topE, int min, int max){
	//straight
	if(topE > min && topE < max){
		motors(55, 40);
	}
	else if(topE > max){
		motors(50, 50);
	}
	else if(topE < min){
		motors(46, 46);
	}
}

//turn left
void leftTurn(){
	cout<<"turn left"<<endl;
	motors(51, 45);
	sleep1(600);
	motors(45, 45);
	sleep1(500);
	bool turnComplete = false;
	bool lookingForTop = false;
	while(!turnComplete){
		bool topThere = lookForTop();
		if(!topThere && !lookingForTop){
			lookingForTop = true;
		}
		if(lookingForTop && topThere){
			motors(48, 48);
			cout<<"Turn complete"<<endl;
			turnComplete = true;
		}
	}
}		

//turn right
void rightTurn(){
	cout<<"turn right"<<endl;
	motors(51, 45);
	sleep1(600);
	motors(51, 51);
	sleep1(500);
	bool turnC = false;
	bool lookingForTop = false;
	while(!turnC){
		bool topThere = lookForTop();
		if(!topThere && !lookingForTop) {
			lookingForTop = true;
		}
		if(topThere && lookingForTop){
			motors(48, 48);
			cout<<"Turn complete"<<endl;
			turnC = true;
		}
	}
}

int colThreshold() {
	int min = 0;
	int max = 100;
	for(int col=0; col < 320; col++) {
		int lum = (int)get_pixel(10, col, 3);
		if(lum < min) {
			min = lum;
		}
		else if(lum > max) {
			max = lum;
		}
	}
	return min + (max-min)*0.3;
}

int rowThreshold(int colNum) {
	int min = 0;
	int max = 100;
	for(int row = 0; row < 240; row++) {
		int lum = (int)get_pixel(row, colNum, 3);
		if(lum < min) { min = lum;}
		else if(lum > max) { max = lum;}
	}
	return min + (max-min)*0.3;
}

void q3()
{
	cout<<"Quadrant 3 chosen"<<endl;
	motors(56, 40);
	sleep1(500);
	int leftCol = 10;
	int rightCol = 300;
	int topRow = 10;

	bool redDetected = false;
	int turnCount = 0;
	bool uTurning = false;
	while(redDetected != true)
	{
		take_picture();
		update_screen();

		if(redDetect(2000) && turnCount > 3) {
			redDetected = true;
			cout<<"Red detected"<<endl;
		}
		
		bool leftPath = false;
		bool rightPath = false;
		bool topPath = false;
	
		double leftError = 0;
		double rightError = 0;
		double topError =  0;
		
		int leftBkPx = 0;
		int leftThreshold = rowThreshold(leftCol);
		for(int row=0; row < 240; row++)
		{	
			int lum = (int)get_pixel(row, leftCol, 3);
			if(lum < leftThreshold){leftBkPx++;}
			leftError = leftError + (lum<leftThreshold)*(row-120);
		}
		if(leftBkPx>60 && leftBkPx <120){leftPath = true;} 
		
		int rightBkPx = 0;
		int rightThreshold = rowThreshold(rightCol);
		for(int row=0; row < 240; row++)
		{
			int lum = (int)get_pixel(row, rightCol, 3);
			if(lum < rightThreshold){rightBkPx++;}
			rightError = rightError + (lum<rightThreshold)*(row-120);
		}
		if(rightBkPx>60 && rightBkPx<120){rightPath=true;}

		int topBlackPix = 0;
		int topThreshold = colThreshold();
		for(int col=0; col < 320; col++)
		{
			int lum = (int)get_pixel(topRow, col, 3);
			if(lum < topThreshold){topBlackPix++;}
			topError = topError + (lum<topThreshold)*(col-160);
		}
		if(topBlackPix > 60 && topBlackPix < 120){topPath = true;}

		topError /= 100;
		leftError /= 100;
		rightError /= 100;
		cout<<"Top: "<<topPath<<endl;
		cout<<"Left: "<<leftPath<<endl;
		cout<<"Right: "<<rightPath<<endl;
		cout<<"TOP ERROR: "<<topError<<endl;
		cout<<"LEFT ERROR: "<<leftError<<endl;
		cout<<"RIGHT ERROR: "<<rightError<<endl<<endl;
		bool turning = turnDetect(leftError, rightError, leftPath, rightPath, topPath);
		if(!turning) {
			if(topPath){straight(topError, -65, 65); uTurning = false;}
			else if(!topPath && topBlackPix < 5 && !leftPath && leftBkPx < 5 && !rightPath && rightBkPx <5){motors(51, 51); uTurning = true;}
		}
		else if(!uTurning){
			if(leftPath){leftTurn(); turnCount++;}
			else if(rightPath){rightTurn(); turnCount++;}
		}
	}
	q4();
}

void q2()
{
	cout<<"Quadrant 2 chosen"<<endl;
	int count = 0;
	bool detectRed = false;
	bool lastStateLeft = false;
	while(detectRed != true)
	{	
		take_picture();
		update_screen();	
		double error=0;
		for(int col=0; col < 320; col++) {
			int lum = (int)get_pixel(120, col, 3);
			error = error + (lum<80)*(col-160);
		}
		int redPixels = 0;
		for(int col = 0; col < 320; col++) {
			for(int row = 0; row < 240; row++)
			{
				double alpha = (double)get_pixel(row, col, 3);
				double red = (double)get_pixel(row, col, 0);
				double green = (double)get_pixel(row, col, 1);
				double blue = (double)get_pixel(row, col, 2);

				if(alpha > 25 && red > 1.5 * green && red > 1.5 * blue) {
					redPixels++;
				}				
			}
		}
		cout<<redPixels<<endl;
		if(redPixels > 2000)
		{
			detectRed = true;
			cout<<"Red detected"<<endl;
		}
		if(error > 2000) {
			motors(53, 48);
			lastStateLeft = false;
		}
		else if(error < -2000)
		{
			motors(48, 43);
			lastStateLeft = true;;
		}
		else if(error == 0)
		{
			motors(45, 50);
		}
		else
		{
			motors(55, 40);
		}
		count++;
		sleep1(100);
	}
	q3();
}

void q1()
{
	cout<<"Quadrant 1 chosen"<<endl;
	camMotorToggle(false);
	char server_addr[15] = {'1', '3', '0', '.', '1', '9', '5', '.', '3', '.', '9', '1'};
	int port = 1024;
	connect_to_server(server_addr, port);
	char please[24] = {'P','l','e','a','s','e'};
	send_to_server(please);
	char password[24];
	receive_from_server(password);
	send_to_server(password);

	motors(65,30);
	sleep1(2500);
	q2();
}

int main()
{
	int err;
	cout<<"TESTING123"<<endl;
	err = init(0);
	cout<<"After init() error="<<err<<endl;
	open_screen_stream();
	camMotorToggle(false);
	q4();
	//motors(45, 50);
	//motors(50, 46);
	return 0;
}
