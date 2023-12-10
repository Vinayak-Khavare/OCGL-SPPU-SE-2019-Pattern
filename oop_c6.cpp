//Write C++ program using STL for sorting and searching user defined records such as personal records 
//(Name, DOB, Telephone number etc) using vector container

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class record{
	
	public:
		
		int id;
		string name;
		string dob;
		long tele;
		
		record(){
			id = 0;
			name = " ";
			dob = "10/05/2003";
			tele = 1000000000;
		}
		
		bool operator==(const record &obj){
			if(id==obj.id){
				return 1;
			}
			else{
				return 0;
			}
		}
		
		bool operator<(const record &obj){
			if(id<obj.id){
				return 1;
			}
			else{
				return 0;
			}
		}
};

vector<record> rec;
void print(record &);
void display();
void insert();
void search();
void dlt();

void display(){
//	vector<record>::iterator i;
	cout<<"\n ID\t Name\t  DOB\t\tTelephone"<<endl;
	for_each(rec.begin(), rec.end(), print);
}

void print(record &obj){
	cout<<obj.id<<"\t "<<obj.name<<"\t "<<obj.dob<<"\t\t"<<obj.tele<<endl;
}

void insert(){
	record obj;
	cout<<"Enter id: ";
	cin>>obj.id;
	cout<<"enter name: ";
	cin>>obj.name;
	cout<<"enter dob: ";
	cin>>obj.dob;
	cout<<"enter telephone no";
	cin>>obj.tele;
	
	rec.push_back(obj);
}

void del(){
	vector<record>::iterator i;
	record obj;
	cout<<"Enter the id : ";
	cin>>obj.id;
	i=find(rec.begin(), rec.end(), obj.id);
	if(i==rec.end()){
		cout<<"not found"<<endl;
	}
	else{
		rec.erase(i);
		cout<<"deleted"<<endl;
	}
}

void search(){
	vector<record>::iterator i;
	record obj;
	cout<<"Enter the id : ";
	cin>>obj.id;
	i=find(rec.begin(), rec.end(), obj.id);
	if(i==rec.end()){
		cout<<"not found"<<endl;
	}
	else{
		cout<<"found"<<endl;
	}
}

bool compare(const record &r1, const record &r2){
	if(r1.id<r2.id){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int ch;
	
	while(true){
		cout<<"\n-----------Menu-----------"
			<<"\n01. Insert"
			<<"\n02. Display"
			<<"\n03. Search"
			<<"\n04. Sort"
			<<"\n05. Delete"
			<<"\n06. Exit"<<endl;
			
		cout<<"Enter your choice: ";
		cin>>ch;
		
		if(ch==1){
			insert();
		}
		
		else if(ch==2){
			display();
		}
		
		else if(ch==3){
			search();
		}
		
		else if(ch==4){
			sort(rec.begin(), rec.end(), compare);
			cout<<"Sorted on id, "<<endl;
			display();
		}
		
		else if(ch==5){
			del();
		}
		
		else if(ch==6){
			cout<<"Thank you!!"<<endl;
			break;
		}
		
		else{
			cout<<"Invalid choice!!"<<endl;
		}
	}
	return 0;
}

