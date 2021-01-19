#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a>b)
	{
		int temp1=b;
		b=a;
		a=temp1;
		if(c<b)
		{
			int temp2=c;
			if(c<a)
			{
				c=b;
				b=a;
				a=temp2;
			}
			else
			{
				c=b;
				b=temp2;
			}
		}
	}
	else
	{
		if(c<a)
		{
			int temp3=c;
			c=b;
			b=a;
			a=temp3;
		}
		else if(c<b)
		{
			int temp4=c;
			c=b;
			b=temp4;
		}
	}
	cout<<a<<" "<<b<<" "<<c;
	return 0;
}
