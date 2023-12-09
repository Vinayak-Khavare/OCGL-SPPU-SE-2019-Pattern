#include<iostream>
#define n 10
using namespace std;

int l;
template<class T>
void selsort(T arr[n]){
	for(int i=0; i<l; i++){
		int m=i;
		for(int j=i; j<(l); j++){
			if(arr[m]>arr[j]){
				m=j;
			}
		}
		if(m!=i){
			T temp = arr[m];
			arr[m] = arr[i];
			arr[i] = temp;
		}
	}
}

template<class T>
void display(T arr[n]){
	cout<<" ";
	for(int i=0; i<l; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int ch;
	int arr1[n];
	float arr2[n];
	
	while(true){
		cout<<"\n\n";
		cout<<"\t----Menu----\n"
			<<"01. Int array."
			<<"\n02. Float array."
			<<"\n03. exit"<<endl;
		cout<<"Enter Choice: ";
		cin>>ch;
		
		if(ch==1){
			cout<<"\nInteger array!!"<<endl;
			cout<<"Enter no of elements: ";
			cin>>l;
			int e;
			for(int i=0; i<l; i++){
				cout<<"Enter element "<<i+1<<": ";
				cin>>e;
				arr1[i] = e;
			}
			
			cout<<"\nCurrent array: ";
			display(arr1);
			selsort(arr1);
			cout<<"After sorting: ";
			display(arr1);
		}
		
		else if(ch==2){
			cout<<"\nFloating array"<<endl;
			cout<<"Enter no of elements: ";
			cin>>l;
			float e;
			for(int i=0; i<l; i++){
				cout<<"Enter element "<<i+1<<": ";
				cin>>e;
				arr2[i] = e;
			}
			
			cout<<"\nCurrent array: ";
			display(arr2);
			selsort(arr2);
			cout<<"After sorting: ";
			display(arr2);
		}
		
		else if(ch==3){
			cout<<"Thank you!!"<<endl;
			break;
		}
		
		else{
			cout<<"Wrong input!!"<<endl;
		}
	}
	
	return 0;
}
