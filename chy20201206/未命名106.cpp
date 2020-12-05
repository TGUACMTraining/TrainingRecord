//预测错误，数组开太大了 


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int jiang[100001],wen[100001];
int main()
{
	int sum[100000]={0};
	long long n,q,k;
	cin>>n>>q;
	int i,j;
	for(i=0;i<n;i++)
	{
		cin>>jiang[i];
	}
	long long l=0;
	for(j=0;j<q;j++)
	{
		cin>>wen[j];
		for(k=0;k<n;k++)
		{
			if(jiang[k]==wen[j])
			{
				sum[l]++;
			}
		}
		l++;
	}
	for(l=0;l<q;l++)
	{
		if(sum[l]==0)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<sum[l]<<endl;
		}
	}
	return 0;
} 
