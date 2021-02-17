#include<iostream>
using namespace std;
int a[10],b[1001];
int main()
{
	int n,i,sum,sum1,sum2;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
		a[b[i]]++;
		sum+=b[i];
	}
	while(1)
	{
		i=1;
		if(a[i]!=0)
		{
			sum1=a[i];
			break;
		}
		else
		{
			i++;
		}
	}
	while(1)
	{
		i=10;
		if(a[i]!=0)
		{
			sum2=a[i];
			break;
		}
		else
		{
			i--;
		}
	}
	
	n-=2;
	int temp=sum/n;
	cout<<sum;
	return 0;
}
