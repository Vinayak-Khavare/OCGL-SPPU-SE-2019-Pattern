#include<iostream>
#include<string>
using namespace std;

class studData2;

class studData1{
	string name;
	int rollno;
	string cls;
	char* div;
	string dob;
	char* bloodgrp;
	static int count;
	
	public:
		studData1(){
			name = "";
			rollno = 0;
			cls = "";
			div = new char;
			dob = "dd/mm/yyyy";
			bloodgrp = new char[4];
		}
		
		~studData1(){
			delete div;
			delete[] bloodgrp;
		}
		
		static int getcount(){
			return count;
		}
		
		void getdata1(studData2*);
		void dispdata1(studData2*);
};

class studData2{
	string address;
	long* tele;
	long* licen;
	
	public:
		studData2(){
			address = "";
			tele = new long;
			licen = new long;
		}
		
		~studData2(){
			delete tele;
			delete licen;
		}
		
		void getdata2(){
			cout<<"Enter address: ";
			cin.get();
			getline(cin, address);
			cout<<"Enter telephone: ";
			cin>>*tele;
			cout<<"Enter license: ";
			cin>>*licen;
		}
		
		void dispdata2(){
			cout<<"Contact address: "<<address<<endl;
			cout<<"Telephone no: "<<*tele<<endl;
			cout<<"License no: "<<*licen<<endl;
		}
};

inline void studData1::getdata1(studData2* s1){
	cout<<"Enter name: ";
	cin>>name;
	cout<<"Enter rollno: ";
	cin>>rollno;
	cout<<"Enter class: ";
	cin>>cls;
	cout<<"Enter division: ";
	cin>>div;
	cout<<"Enter dob(dd/mm/yyyy): ";
	cin>>dob;
	cout<<"Enter blood group: ";
	cin>>bloodgrp;
	
	s1->getdata2();
	count++;
}

inline void studData1::dispdata1(studData2* s1){
	cout<<"Name: "<<name<<endl;
	cout<<"Roll number: "<<rollno<<endl;
	cout<<"Class: "<<cls<<endl;
	cout<<"Division: "<<div<<endl;
	cout<<"DOB: "<<dob<<endl;
	cout<<"Blood group: "<<bloodgrp<<endl;
	
	s1->dispdata2();
}

int studData1::count = 0;

int main(){
	studData1* s1[100];
	studData2* s2[100];
	int n;
	char ch;
	
	do{
		s1[n] = new studData1;
		s2[n] = new studData2;
		
		s1[n]->getdata1(s2[n]);
		
		cout<<"Do you want to add another student(Y/N): ";
		cin>>ch;
		n++;
		
	}while(ch=='y'||ch=='Y');
	
	for(int i=0; i<n; i++){
		cout<<"-------------------------------------------"<<endl;
		s1[i]->dispdata1(s2[i]);
	}
	cout<<"-------------------------------------------"<<endl;
	cout<<"Total strength: "<<studData1::getcount()<<endl;
	cout<<"-------------------------------------------"<<endl;
	
	for(int i=0; i<n; i++){
		delete s1[i];
		delete s2[i];
	}
	
	return 0;
}
