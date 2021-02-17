#include<iostream>
using namespace std;
int main()
{
	int a,b,c,max;
	cin>>a>>b>>c;
	max=a;
	if(b>max)
	{
		max=b;
		if(c>b)
		{
			max=c;
		}
	}
	else if(c>max)
	{
		max=c;
	}
	cout<<max;
	return 0;
}
