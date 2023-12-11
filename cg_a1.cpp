#include<iostream>
#include<graphics.h>
using namespace std;

class polygon;

class point{
	public:
		int x, y;
};

class polygon{
	point p[20];
	int inter[20], x, y;
	int v, xmin, ymin, xmax, ymax;
	
	public:
		int c;
		void read();
		void setmnmx();
		void display();
		void setpoints(float);
		void linefill(int);
};

void polygon::read(){
	int i;
	cout<<"Enter the no of vertices: ";
	cin>>v;
	
	if(v>2){
		for(i = 0; i<v; i++){
			cout<<"Enter coordinates of vertex "<<i+1<<" : ";
			cin>>p[i].x>>p[i].y;
		}
		p[i].x = p[0].x;
		p[i].y = p[0].y;
		xmin = xmax = p[0].x;
		ymin = ymax = p[0].y;
	}
	else{
		cout<<"Invalid no of vertices: "<<endl;
		read();
	}
}

void polygon::setmnmx(){
	for(int i = 0; i<v; i++){
		if(xmin>p[i].x)
			xmin = p[i].x;
		if(xmax<p[i].x)
			xmax = p[i].x;
		if(ymin>p[i].y)
			ymin = p[i].y;
		if(ymax<p[i].y)
			ymax = p[i].y;
	}
}

void polygon::display(){
	int ch;
	float s;
	while(true){
		cout<<"\n------Menu------"
			<<"\n1. Scanfill"
			<<"\n2. Exit"<<endl;
		
		cout<<"enter choice: ";
		cin>>ch;
		
		if(ch==1){
			cout<<"Entered Scan fill, "<<endl;
			s = ymin+0.01;
			delay(10);
			cleardevice();
			setpoints(s);
			linefill(s);
		}
		
		else if(ch==2){
			cout<<"Thank you!!"<<endl;
			break;
		}
		
		else{
			cout<<"Invalid choice!!"<<endl;
		}
	}
}

void polygon::setpoints(float z){
	int x1, y1, x2, y2, temp;
	for(int i=0; i<v; i++){
		x1 = p[i].x;
		y1 = p[i].y;
		x2 = p[i+1].x;
		y2 = p[i+1].y;
		if(y2<y1){
			temp = x1;
			x1 = x2;
			x2 = temp;
			temp = y1; 
			y1 = y2;
			y2 = temp;
		}
		if(z<=y2 && z>=y1){
			if((y2-y1)==0){
				x = x1;
			}
			else{
				x=((x2-x1)*(z-y1))/(y2-y1);
				x = x1;
			}
			if(x>=xmin && x<=xmax){
				inter[c++]=x;
			}
		}
	}
}

void polygon::linefill(int z){
	int i;
	for(i=0; i<v; i++){
		line(p[i].x, p[i].y, p[i+1].x, p[i+1].y);
	}
	delay(10);
	for(i=0; i<c; i++){
		line(inter[i], z, inter[i+1], z);
	}
}

int main(){
	polygon poly;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	initwindow(500, 600);
	cleardevice();
	
	poly.read();
	poly.setmnmx();
	cleardevice();
	
	int color;
	cout<<"Enter your colour choice(0-15): ";
	cin>>color;
	
	setcolor(color);
	poly.display();
	
	closegraph();
	getch();
	
	return 0;
}
