#include<iostream>
using namespace std;
int main()
{
	int a,sum,c;
	char b;
	cin>>a>>b;
	if(a<=1000)
	{
		sum=8;
	}
	else 
	{
		a-=1000;
		c=a/500;
		if(c*500<=a)
		{
			c++;
		}
		sum=8+4*c;
	}
	if(b=='y')
	{
		sum+=5;
	}
	cout<<sum;
	return 0;
}
