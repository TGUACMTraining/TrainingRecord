#include<iostream>
using namespace std;
int a[100001],sum[100001];
int main()
{
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		for(j=i;j>=0;j--)
		{
			if(a[i]>a[j])
			{
				sum[i]++;
			}
		}
	}
	for(int k=0;k<n;k++)
	{
		cout<<sum[k]<<" ";
	}
	return 0;
}
