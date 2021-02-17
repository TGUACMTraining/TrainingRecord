#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
const double pec=1e-10;
int main()
{
	double a,b,c,d,e,x1,x2;
	cin>>a>>b>>c;
	d=b*b-4*a*c;
	if(d<0||fabs(d)<pec)
	{
		cout<<"No answer!";
	}
	else
	{
	e=sqrt(d);
	x1=(e-b)/(2*a);
	x2=(-e-b)/(2*a);
	if(x1==x2)
	{
		cout<<"x1=x2="<<x1;
	}
	else if(x1>x2)
	{
		printf("x1=%.5lf",x2);
		cout<<";";
		printf("x2=%.5lf",x1);
	}
	else if(x2>x1)
	{
		printf("x1=%.5lf",x1);
		cout<<";";
		printf("x2=%.5lf",x2);
	}
    }
	return 0;
}
