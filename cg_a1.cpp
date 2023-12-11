#include<iostream>
#include<graphics.h>
using namespace std;

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int xmax = getmaxx(), ymax = getmaxy();
	
	int n;
	cout<<"Enter no. of vertices: ";
	cin>>n;
	
	int points[(n+1)*2];
	int x, y, i=0, j=0;
	while(i<((n)*2) && j<n){
		cout<<"Enter x and y coordinate for vertex "<<j+1<<" : ";
		cin>>x>>y;
		points[i]=x;
		i++;
		points[i]=y;
		i++;
		j++;
	}
	points[n*2]=points[0];
	points[(n*2)+1]=points[1];
	
	drawpoly(n+1, points);
	fillpoly(n+1, points);
	
	getch();
	closegraph();
	return 0;
}
