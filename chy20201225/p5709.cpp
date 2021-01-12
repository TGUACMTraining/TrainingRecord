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
	}
	else if(t==0)
	{
		c=m;
	}
	c=m-d;
	cout<<c;
	return 0;
}
