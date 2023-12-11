#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	initwindow(1000, 1000);
	
	float a[3][3];
	cout<<"Enter x1, y1: ";
	cin>>a[0][0]>>a[1][0];
	cout<<"Enter x2, y2: ";
	cin>>a[0][1]>>a[1][1];
	cout<<"Enter x3, y3: ";
	cin>>a[0][2]>>a[1][2];
	
	a[2][0]=a[2][1]=a[2][2]=1;
	
//	setbkcolor(WHITE);
//	setcolor(BLACK);
	
	line(a[0][0], a[1][0], a[0][1], a[1][1]);
	line(a[0][1], a[1][1], a[0][2], a[1][2]);
	line(a[0][2], a[1][2], a[0][0], a[1][0]);
	delay(100);
	
	int ch;
	while(true){
		cout<<"\n1. Translation"
			<<"\n2. Scaling"
			<<"\n3. Rotation"
			<<"\n4. Exit"<<endl;
			
		cout<<"Enter your choice: ";
		cin>>ch;
		
		if(ch==1){
			cleardevice();
			cout<<"\nTanslation: "<<endl;
			float b[3][3], c[3][3];
			b[0][0]=b[1][1]=b[2][2]=1;
			b[0][1]=b[1][0]=b[1][2]=b[0][2]=0;
			cout<<"Enter tx and ty: ";
			cin>>b[2][0]>>b[2][1];
			for(int i=0; i<3; i++){
				for(int j=0; j<3; j++){
					c[i][j]=0;
					for(int k=0; k<3; k++){
						c[i][j]+=b[i][k]*a[k][j];
					}
				}
			}
			setcolor(YELLOW);
			line(c[0][0], c[1][0], c[0][1], c[1][1]);
			line(c[0][1], c[1][1], c[0][2], c[1][2]);
			line(c[0][2], c[1][2], c[0][0], c[1][0]);
			delay(1000);
		}
		
		else if(ch==2){
			cleardevice();
			cout<<"\nScaling: "<<endl;
			float b[3][3], c[3][3];
			b[2][2]=1;
			b[0][1]=b[2][0]=b[2][1]=b[1][0]=b[1][2]=b[0][2]=0;
			cout<<"Enter sx and sy: ";
			cin>>b[0][0]>>b[1][1];
			for(int i=0; i<3; i++){
				for(int j=0; j<3; j++){
					c[i][j]=0;
					for(int k=0; k<3; k++){
						c[i][j]+=b[i][k]*a[k][j];
					}
				}
			}
			setcolor(BLUE);
			line(c[0][0], c[1][0], c[0][1], c[1][1]);
			line(c[0][1], c[1][1], c[0][2], c[1][2]);
			line(c[0][2], c[1][2], c[0][0], c[1][0]);
			delay(1000);
		}
		
		else if(ch==3){
			cleardevice();
			cout<<"\nRotation: "<<endl;
			
			float z, ang;
			cout<<"Angle in degrees: ";
			cin>>z;
			
			ang = (z*3.14)/180;
			
			float b[3][3], c[3][3];
			b[0][0]=b[1][1]=cos(ang);
			b[2][2]=1;
			b[0][1]=sin(ang);
			b[1][0]=(-sin(ang));
			b[2][0]=b[2][1]=b[1][2]=b[0][2]=0;
			
			for(int i=0; i<3; i++){
				for(int j=0; j<3; j++){
					c[i][j]=0;
					for(int k=0; k<3; k++){
						c[i][j]+=b[i][k]*a[k][j];
					}
				}
			}
			setcolor(GREEN);
			line(c[0][0], c[1][0], c[0][1], c[1][1]);
			line(c[0][1], c[1][1], c[0][2], c[1][2]);
			line(c[0][2], c[1][2], c[0][0], c[1][0]);
			delay(1000);
		}
		
		else if(ch==4){
			cout<<"Thank you!!"<<endl;
			break;
		}
		
		else{
			cout<<"Invalid input"<<endl;
		}
	}
	
	closegraph();
	getch();
	return 0;
}
