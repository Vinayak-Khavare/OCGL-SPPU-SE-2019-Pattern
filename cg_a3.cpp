#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void ddaline(float x1, float y1, float x2, float y2){
	float x, y, xinc, yinc, steps, dx, dy;
	
	dx = abs(x2-x1);
	dy = abs(y2-y1);
	
	if(dx>dy){
		steps = dx;
	}
	else{
		steps = dy;
	}
	
	xinc = (x2-x1)/steps;
	yinc = (y2-y1)/steps;
	
	x = x1;
	y = y1;
	putpixel(round(x), round(y), RED);
	
	for(int i=0; i<steps; i++){
		x+=xinc;
		y+=yinc;
		putpixel(round(x), round(y), RED);
	}
}

void bresenhamcircle(int xc, int yc, int rad){
	int x, y, dec;
	
	dec = 3-(2*rad);
	x=0;
	y=rad;
	
	while(y>=x){
		putpixel(xc+x, yc+y, 3);
		putpixel(xc+x, yc-y, 3);
		putpixel(xc-x, yc+y, 3);
		putpixel(xc-x, yc-y, 3);
		putpixel(xc+y, yc+x, 3);
		putpixel(xc+y, yc-x, 3);
		putpixel(xc-y, yc+x, 3);
		putpixel(xc-y, yc-x, 3);
		x++;
		
		if(dec>0){
			y--;
			dec = dec+4*(x-y)+10;
		}
		else{
			dec = dec+4*x+6;
		}
	}
}

int main(){
	float x1, y1, x2, y2, x3;
	int x, y, r;
	
	cout<<"Enter x1: ";
	cin>>x1;
	cout<<"Enter y1: ";
	cin>>y1;
	cout<<"enter x2: ";
	cin>>x2;

	x3 = (x1+x2)/2;
	y2 = y1 - sqrt(pow((x2-x1), 2) - pow((x2-x1)/2, 2)); 
	
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
//	ddaline for triangle
	ddaline(x1, y1, x2, y1);
	ddaline(x2, y1, x3, y2);
	ddaline(x3, y2, x1, y1);
	
//	for inner circle
	x = x3;
	y = y2 + 2*(y1-y2)/3;
	r = (y1-y2)/3;
	bresenhamcircle(x, y, r);
	
//	for outer circle;
	r = 2*(y1-y2)/3;
	bresenhamcircle(x, y, r);
	
	delay(50000);
	closegraph();
	getch();
	
	return 0;
}
