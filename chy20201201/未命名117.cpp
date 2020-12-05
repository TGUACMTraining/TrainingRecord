#include<iostream>
using namespace std;
int a[100001];
int main()
{
	int i,n=0;
	int x;
	cin>>x;
	while(x!=0)
	{
		a[++n]=x;
		cin>>x;
	}
	for(i=n;i>=1;i--)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
