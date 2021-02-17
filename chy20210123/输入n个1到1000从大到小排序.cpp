#include<iostream>
using namespace std;
int main()
{
	int book[1001],i,n,t;
	for(i=0;i<=1000;i++)
	{
		book[i]=0;
	}
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>t;
		book[t]++;
	}
	int j;
	for(i=1000;i>=0;i--)
	{
		for(j=1;j<=book[i];j++)
		{
			cout<<i<<" ";
		}
	}
	return 0;
}
