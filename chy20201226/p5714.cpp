#include<iostream>
using namespace std;
int main()
{
	double m,h,mi;
	cin>>m>>h;
	mi=m/(h*h);
	if(mi<18.5)
	{
		cout<<"Underweight";
	}
	else if(mi>=18.5&&mi<24)
	{
		cout<<"Normal";
	}
	else
	{
		cout<<mi<<endl<<"Overweight";
	}
	return 0;
}
