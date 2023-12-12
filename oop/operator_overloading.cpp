#include <iostream>
using namespace std;
class Complex
{
private:
	int real,img;
public:
	Complex()
	{
		real = 0; 
		img = 0;
	}
	Complex(int r,int i)
	{
		real = r;
		img = i;
	}
	Complex operator+(Complex c2)
	{
		Complex c3;
		c3.real = real + c2.real;
		c3.img = img+c2.img;
		return c3;
	}
	Complex operator*(Complex c2)
	{
		Complex c3;
		c3.real =(real*c2.real - img*c2.img);
		c3.img = (real*c2.img + img*c2.real);
		return c3;
	}
	friend void operator>>(istream &in,Complex&c){
		cout<<"Enter real part:\n";
		in>>c.real;
		cout<<"Enter imaginary part:\n";
		in>>c.img;
	}
	friend void operator<<(ostream &out,Complex &c){
		out<<c.real<<" + "<<c.img<<"i"<<endl;
	}
	void display(){
		cout<<real<<" + "<<img<<"i"<<endl;
	}
};
int main()
{
	int n;
	cout<<"Enter 1 to add complex numbers :\n";
	cout<<"Enter 2 to multiply complex numbers:\n";
	cin>>n;
		Complex c1,c2,c3;
		cout<<"Enter first complex number:\n";
		cin>>c1;
		cout<<"Enter second complex number:\n";
		cin>>c2;
	switch(n)
	{
	case 1:
	{
		c3 = c1+c2;
		cout<<"Answer = "<<c3;
		break;
	}
	case 2:
	{
		c3 = c1*c2;
		cout<<"Answer = "<<c3;
		break;
	}
	default:
	{
		cout<<"inavlid input!!\n";
	}
	}
	return 0;
}
