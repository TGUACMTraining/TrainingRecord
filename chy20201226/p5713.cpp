#include<iostream>
using namespace std;
int main()
{
	int n,l,lu;
	cin>>n;
	l=5*n;
	lu=11+3*n;
	if(lu>l)
	{
		cout<<"Local";
	}
	else
	{
		cout<<"Luogu";
	}
	return 0;
}
