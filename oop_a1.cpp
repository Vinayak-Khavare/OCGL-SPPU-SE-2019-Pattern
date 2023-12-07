#include<iostream>
using namespace std;

class complex{
    public:
    int real, img;
    complex();
    complex operator + (complex);
    complex operator * (complex);
    friend ostream operator << (ostream&, complex&);
    friend istream operator >> (istream&, complex&);
};

complex::complex(){
    real = 0;
    img = 0;
}

complex complex :: operator + (complex obj){
    complex temp;
    temp.real = real + obj.real;
    temp.img = img +obj.img;
    return temp;
}

complex complex :: operator * (complex obj){
    complex temp;
    temp.real = (real*obj.real - img*obj.img);
    temp.img = (real*obj.img + img*obj.real);
    return temp;
}

ostream &operator << (ostream &out, complex &obj){
    out<<" "<<obj.real;
    out<<" + "<<obj.img<<"i";
    return out;
}

istream &operator >> (istream &in, complex &obj){
    in>>obj.real;
    in>>obj.img;
    return in;
}

int main(){
    complex a, b, c, d;
    istream in;
    ostream out;
    
    cout<<"The first complex number is:"<<endl;
    cout<<"Enter real and img of the complex number, ";
    in>>a;

    cout<<"The second complex number is:"<<endl;
    cout<<"Enter real and img of the complex number, ";
    in>>b;

    c = a + b;
    cout<<"The addition is: ";
	out<<c<<endl;

    d = a*b;
    cout<<"The multiplication is: ";
	out<<d<<endl;
    
    return 0;
}
