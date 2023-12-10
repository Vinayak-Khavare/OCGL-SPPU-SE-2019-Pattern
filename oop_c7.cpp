#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main(){
	typedef map<string,int> mapType;
	mapType m;

	string state;
	int population;
	char ch;
	do{
		cout<<"Enter the name and population of the state: ";
		cin>>state>>population;

		m.insert(make_pair(state, population));

		cout<<"Do yant to continue adding states and their population(Y/N): ";
		cin>>ch;

	}while(ch=='y' || ch=='Y');

	mapType :: iterator i;

	for(i = m.begin(); i!=m.end(); i++){
		cout<<i->first<<" : "<<i->second<<endl;
	}

	do{
		cout<<"\nEnter that state you want to know the population of: ";
		cin>>state;
		i = m.find(state);
		if( i != m.end() ) 
		    cout << state <<"'s populations is "<< i->second << " million\n";
		else
		    cout <<state<<" is not in populationMap" <<endl;
		    
		cout<<"Do you wish to continue?(y/n):";
		cin>>ch;
	}while(ch=='y'||ch=='Y');

	m.clear();

	cout<<"Thank you!!"<<endl;
	
	return 0;
}