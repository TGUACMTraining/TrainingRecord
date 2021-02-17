#include<iostream>
#include<cstdio>
using namespace std;
int a[11]={0},b[1001];
int main()
{
	int n,i,j,k=0;
	cin>>n;
	double sum=0,sum2=0;
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
		sum2+=b[i];
		j=b[i];
		a[j]++;
	}
	while(1)
	{
		if(a[0]!=0)
		{
			break;
		}
		else if(a[k]!=0)
		{
			a[k]--;
			break;
		}
		else if(a[k]==0)
		{
			k++;
		}
	}
	k=10;
	while(1)
	{
		if(a[k]!=0)
		{
			a[k]--;
			break;
		}
		else
		{
			k--;
		}
	}
	for(i=1;i<=11;i++)
	{
		sum+=i*a[i];
	}
	
	double sum1;
	sum1=sum/(n-2.0);
	printf("%.2lf",sum1);
	return 0;
}
