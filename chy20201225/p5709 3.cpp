#include<iostream>
using namespace std;
int main()
{
	int m,t,s;
	int d;
	cin>>m>>t>>s;
	if(t==0)
	{
		cout<<0;
		return 0;
	}
	else
	{
		int c=s/t;
		if(c*t!=s)
		{
			d=m-c-1;
			if(d<0)
			{
				d=0;
				cout<<d;
			}
			else
			{
				cout<<d;
			}
		}
		else
		{
			d=m-c;
			if(d<0)
			{
				cout<<0;
			}
			else
			{
				cout<<d;
			}
		}
		return 0;
	}
} 
