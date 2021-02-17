#include<iostream>
using namespace std;
int main()
{
	int n,sum=0;
	char a;
	cin>>n>>a;
	int n1=n-1000;
	if(n<=1000)
	{
		sum+=8;
	}
	else
	{
		int n2=n1/500;
		if(n1%500!=0)
		{
			n2++;
		}
		sum+=n2*4+8;
	}
	if(a=='y')
	{
		sum+=5;
	}
	cout<<sum;
	return 0;
}
