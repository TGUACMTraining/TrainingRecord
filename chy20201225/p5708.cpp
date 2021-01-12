#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double a,b,c,d;
	cin>>a>>b>>c;
	d=sqrt(((a+b+c)/2-a)*((a+b+c)/2-b)*((a+b+c)/2-c)*(a+b+c)/2);
	printf("%.1lf",d);
	return 0;
}
