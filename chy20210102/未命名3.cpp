#include<iostream>
using namespace std;
int a[100];
int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	cout<<sum;
	return 0;
}
