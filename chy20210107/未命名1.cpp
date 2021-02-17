#include<iostream>
#include<cstdio>
using namespace std;
int a[1001];
int main()
{
	int n;
	double sum1,sum;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sum1=sum/n;
	printf("%.2lf",sum1);
	return 0;
}
