#include<iostream>
#include<string>
using namespace std;

class publication{
	
	string title;
	float price;
	
	public:
		void add(){
			cout<<"Enter the title of publication: ";
			cin.get();
			getline(cin, title);
			cout<<"Enter the price of publication: ";
			cin>>price;
		}
		
		void disp(){
			cout<<"Publication title: "<<title<<endl;
			cout<<"Publication price: "<<price<<endl;
		}
};

class book : public publication{
	int pages;
	
	public:
		void add_book(){
			try{
				add();
				cout<<"Enter the Pages of the book: ";
				cin>>pages;
				if(pages<=0){
					throw pages;
				}
			}
			catch(...){
				cout<<"Invalid Page count!!"<<endl;
				pages = 0;
			}		
		}
		
		void disp_book(){
			disp();
			cout<<"Pages count: "<<pages<<endl;
		}
};

class tape : public publication{
	float time;
	
	public:
		void add_tape(){
			try{
				add();
				cout<<"Enter the playing time of the tape: ";
				cin>>time;
				if(time<=0){
					throw time;
				}
			}
			catch(...){
				cout<<"Inavalid play duration!!"<<endl;
				time = 0;
			}
		}
		
		void disp_tape(){
			disp();
			cout<<"Play duration of the Tape: "<<time<<" min"<<endl;
		}
};

int main(){
	book s1[10];
	tape s2[10];
	
	int ch, s1_count = 0, s2_count = 0;
	
	while(true){
		cout<<"\n--------------Menu--------------"
			<<"\n01. Add information to book"
			<<"\n02. Add information to tape"
			<<"\n03. Display books information"
			<<"\n04. Display tapes information"
			<<"\n05. Exit"<<endl;
			
		cout<<"Enter choice: ";
		cin>>ch;
		
		if(ch==1){
			s1[s1_count].add_book();
			s1_count++;
		}
		
		else if(ch==2){
			s2[s2_count].add_tape();
			s2_count++;
		}
		
		else if(ch==3){
			cout<<"*****BOOK PUBLICATION DATABASE*****"<<endl;
			for(int i=0; i<s1_count; i++){
				s1[i].disp_book();
			}
		}
		
		else if(ch==4){
			cout<<"*****TAPE PUBLICATION DATABASE*****"<<endl;
			for(int i=0; i<s2_count; i++){
				s2[i].disp_tape();
			}
		}
		
		else if(ch==5){
			cout<<"Thank you!!"<<endl;
			break;
		}
		
		else{
			cout<<"Invalid choice!!"<<endl;
		}
		
		cout<<"--------------------------------"<<endl;
	}
}
