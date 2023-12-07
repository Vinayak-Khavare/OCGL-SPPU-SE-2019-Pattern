#include <iostream>
using namespace std;

class Complex{
	private:
		int real,imag;
	public:
		Complex(){
			real= 0;
			imag = 0;
		}
		
		friend istream & operator >> (istream &, Complex &); // Input 
		friend ostream & operator << (ostream &, Complex &); // Output
		
		Complex operator *(Complex obj){
			Complex op;
			if(imag>0 and obj.imag>0){
				op.real = (real*obj.real)-(imag*obj.imag);
				op.imag = (real*obj.imag)+(obj.real*imag);
			}
			else if(imag>0 and obj.imag<0){
				op.real = (real*obj.real)+(-(imag*obj.imag));
				op.imag = (real*obj.imag)+(obj.real*imag);
			}
			else if(imag<0 and obj.imag>0){
				op.real = (real*obj.real)+(-(imag*obj.imag));
				op.imag = (real*obj.imag)+(obj.real*imag);
			}
			else{
				op.real = real*obj.real-(imag*obj.imag);
				op.imag = (real*obj.imag)+(obj.real*imag);
			}
			return op;
		}
		
		Complex operator +(Complex obj){
			Complex temp;
			temp.real = real + obj.real;
			temp.imag = imag + obj.imag;
			return temp;
		}
};

istream &operator >>(istream &is, Complex &obj){
	is>>obj.real;
	is>>obj.imag;
	return is;
}

ostream &operator <<(ostream &out, Complex &obj){
	if(obj.imag>0){
		out<<obj.real<<" +"<<obj.imag<<"i"<<endl;
	}
	else{
		out<<obj.real<<" "<<obj.imag<<"i"<<endl;
	}
	return out;
}

int main(){
	
	Complex a, b;
	
	cout<<"Enter coefficents of real and imaginary part of first number: "<<endl;
	cin>>a;
	cout<<"Enter coefficents of real and imaginary part of second number: "<<endl;
	cin>>b;
	
	cout<<"Multiplication of given complex numbers is, ";
	Complex c = a*b;
	cout<<c;
	
	cout<<"Addition of given complex number is, ";
	Complex d = a+b;
	cout<<d;
	
	return 0;
}

