#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class student{
	string name;
	int rollno;
	float cgpa;
	
	public:
		void store(){
			cout<<"Enter the name: ";
			cin.ignore();
			getline(cin, name);
			cout<<"Enter rollno: ";
			cin>>rollno;
			cout<<"Enter CGPA obtained: ";
			cin>>cgpa;
		}
		
		void print(){
			cout<<"Name: "<<name<<endl;
			cout<<"Roll no: "<<rollno<<endl;
			cout<<"CGPA: "<<cgpa<<endl;
		}
};

int main(){
	student obj[5];
	fstream f;
	int n;
	
	f.open("oop_b4.txt", ios::out);
	cout<<"Enter the no of students you want to store: ";
	cin>>n;
	
	for(int i=0; i<n; i++){
		cout<<"Information of "<<i+1<<" student"<<endl;
		obj[i].store();
		f.write((char*)&obj[i], sizeof obj[i]);		
	}	
	f.close();
	
	f.open("oop_b4.txt", ios::in);
	for(int i=0; i<n; i++){
		cout<<"Student "<<i+1<<endl;
		f.read((char*)&obj[i], sizeof obj[i]);
		obj[i].print();
	}
	f.close();

	return 0;
}
