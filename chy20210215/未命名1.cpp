#include<iostream>
using namespace std;
int a[1001];
int main()
{
	int n,k=0;
	cin>>n;
	int c=n;
	while(n!=1)
	{
		if(n%2==0)
		{
			n=n/2;
			a[k]=n;
			k++;
		}
		else
		{
			n=n*3+1;
			a[k]=n;
			k++;
		}
	}
	for(k=k-1;k>=0;k--)
	{
		cout<<a[k]<<" ";
	}
	cout<<c<<" ";
	return 0;
}
