#include<iostream>
using namespace std;
int main()
{
	int m,t,s,c;
	cin>>m>>t>>s;
	int d=s/t;
	if(d*t!=s&&t!=0)
	{
		d++;
		c=m-d;
	}
	else if(t==0)
	{
		c=0;
	}
	cout<<c;
	return 0;
}
