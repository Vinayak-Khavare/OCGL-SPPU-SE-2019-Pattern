#include<iostream>
#include<graphics.h>
#include<string>
#include<math.h>
using namespace std;

int xmin, xmax, ymin, ymax;

class lines{
	public:
		int x1, y1, x2, y2;
};

int sign(int x){
	if(x>0){
		return 1;
	}
	else{
		return 0;
	}
}

void clip(lines ln){
	int bits[4], byte[4], i, var;
	
	bits[0] = sign(xmin - ln.x1);
	byte[0] = sign(xmin - ln.x2);
	bits[1] = sign(ln.x1 - xmax);
	byte[1] = sign(ln.x2 - xmax);
	bits[2] = sign(ymin - ln.y1);
	byte[2] = sign(ymin - ln.y2);
	bits[3] = sign(ln.y1 - ymax);
	byte[3] = sign(ln.y2 - ymax);
	
	string initial = "", end = "", temp = "";
	
	for(i = 0; i<4; i++){
		if(bits[i]==0){
			initial+='0';
		}
		else{
			initial+='1';
		}
	}
	
	for(i = 0; i<4; i++){
		if(byte[i]==0){
			end+='0';
		}
		else{
			end+='1';
		}
	}
	
	float m = (ln.y2 - ln.y1)/(float)(ln.x2 - ln.x1);
	float c = ln.y1 - m*ln.x1;
	
	setcolor(RED);
	if(initial==end && end=="0000"){
		line(ln.x1, ln.y1, ln.x2, ln.y2);
	}
	else{
		for(i = 0; i<4; i++){
			int val = (bits[i] && byte[i]);
			if(val==0){
				temp+='0';
			}
			else{
				temp+='1';
			}
		}
		
		if(temp!="0000"){
			return;
		}
		
		for(i=0; i<4; i++){
			if(bits[i]==byte[i]){
				continue;
			}
			
			if(i==0 && bits[i]==1){
				var = round(m*xmin + c);
				ln.y1 = var;
				ln.x1 = xmin;
			}
			
			if(i==0 && byte[i]==1){
				var = round(m*xmin + c);
				ln.y2 = var;
				ln.x2 = xmin;
			}
			
			if(i==1 && bits[i]==1){
				var = round(m*xmax + c);
				ln.y1 = var;
				ln.x1 = xmax;
			}
			
			if(i==1 && byte[i]==1){
				var = round(m*xmax + c);
				ln.y2 = var;
				ln.x2 = xmax;
			}
			
			if(i==2 && bits[i]==1){
				var = round((float)(ymin-c)/m);
				ln.x1 = var;
				ln.y1 = ymin;
			}
			
			if(i==2 && byte[i]==1){
				var = round((float)(ymin-c)/m);
				ln.x2 = var;
				ln.y2 = ymin;
			}
			
			if(i==3 && bits[i]==1){
				var = round((float)(ymax-c)/m);
				ln.x1 = var;
				ln.y1 = ymax;
			}
			
			if(i==3 && byte[i]==1){
				var = round((float)(ymax-c)/m);
				ln.x2 = var;
				ln.y2 = ymax;
			}
		}
		
		bits[0] = sign(xmin - ln.x1);
		byte[0] = sign(xmin - ln.x2);
		bits[1] = sign(ln.x1 - xmax);
		byte[1] = sign(ln.x2 - xmax);
		bits[2] = sign(ymin - ln.y1);
		byte[2] = sign(ymin - ln.y2);
		bits[3] = sign(ln.y1 - ymax);
		byte[3] = sign(ln.y2 - ymax);
		
		initial = "", end = "";
		
		for(i = 0; i<4; i++){
			if(bits[i]==0){
				initial+='0';
			}
			else{
				initial+='1';
			}
		}
		
		for(i = 0; i<4; i++){
			if(byte[i]==0){
				end+='0';
			}
			else{
				end+='1';
			}
		}
		
		if(initial==end && end=="0000"){
			line(ln.x1, ln.y1, ln.x2, ln.y2);
			return;
		}
		else{
			return;
		}
	}
}

int main()
{
    xmin = 40;
    xmax = 100;
    ymin = 40;
    ymax = 80;
 
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
 
    line(xmin, ymin, xmax, ymin);
    line(xmax, ymin, xmax, ymax);
    line(xmax, ymax, xmin, ymax);
    line(xmin, ymax, xmin, ymin);
 
	lines mylines[4];
 
    mylines[0].x1 = 30;
    mylines[0].y1 = 65;
    mylines[0].x2 = 55;
    mylines[0].y2 = 30;
 
    mylines[1].x1 = 60;
    mylines[1].y1 = 20;
    mylines[1].x2 = 100;
    mylines[1].y2 = 90;
 
    mylines[2].x1 = 60;
    mylines[2].y1 = 100;
    mylines[2].x2 = 80;
    mylines[2].y2 = 70;
 
    mylines[3].x1 = 85;
    mylines[3].y1 = 50;
    mylines[3].x2 = 120;
    mylines[3].y2 = 75;
 
    for (int i = 0; i < 4; i++) {
        line(mylines[i].x1, mylines[i].y1,
             mylines[i].x2, mylines[i].y2);
        delay(1000);
    }
 
    for (int i = 0; i < 4; i++) {
        clip(mylines[i]);
        delay(1000);
    }
    delay(4000);
    getch();

    closegraph();
    return 0;
}
