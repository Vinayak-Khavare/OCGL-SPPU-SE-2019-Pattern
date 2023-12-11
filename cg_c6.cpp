#include<iostream>
#include<graphics.h>

using namespace std;

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	initwindow(500, 500);
	cleardevice();
//	delay(100);
	
	int x = 250, y=200, r=20;
	
	while(y>125){
		cleardevice();
		line(0,250,125,0);
		line(125,0,250,250);
		line(250,250,375,0);
		line(375,0,500,250);
		line(0,300,500,300);
		circle(x,y,r);
		floodfill(x,y,WHITE);
		y=y-5;
		delay(150);
	}
	
	while(y<250){
		cleardevice();
		line(0,250,125,0);
		line(125,0,250,250);
		line(250,250,375,0);
		line(375,0,500,250);
		line(0,300,500,300);
		circle(x,y,r);
		floodfill(x,y,WHITE);
		y=y+5;
		delay(150);
	}
	
	closegraph();
	getch();
	
	return 0;
}
