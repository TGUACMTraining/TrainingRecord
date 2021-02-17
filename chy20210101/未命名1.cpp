#include<iostream>
#include<cstdio>
int a[11]={0},b[1001];
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i,j,m=11;
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
		a[b[i]]++;
	}
	while(1)
	{
		j=1;
		if(a[j]!=0)
		{
			a[j]--;
			break;
		}
		j++;
	}
	while(1)
	{
		if(a[m]!=0)
		{
			a[m]--;
			break;
		}
		m--;
	}
	int sum=0;
	
	for(int k=1;k<=10;k++)
	{
		cout<<a[k];
	}
	
	return 0;
}
