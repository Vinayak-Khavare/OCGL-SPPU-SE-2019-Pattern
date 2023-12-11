#include<iostream>
#include<graphics.h>

using namespace std;

int main(){
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	
	initwindow(width, height);
	int x=100, y=100;
	
	while(true){
		cleardevice();
		circle(x, y, 50);
		fillellipse(x, y, 50, 50);
		if(GetAsyncKeyState(VK_RIGHT)){
			x+=10;
		}
		else if(GetAsyncKeyState(VK_LEFT)){
			x-=10;
		}
		else if(GetAsyncKeyState(VK_UP)){
			y-=10;
		}
		else if(GetAsyncKeyState(VK_DOWN)){
			y+=10;
		}
		if(GetAsyncKeyState(VK_RETURN)){
			break;
		}
		delay(10);
	}
	closegraph();
	
	return 0;
}
