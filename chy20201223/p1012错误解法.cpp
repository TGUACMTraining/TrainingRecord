#include<iostream>
using namespace std;
int a[10000];
int main()
{
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int j;
	for(i=0;i<n;i++)
	{
		
		
			for(j=i+1;j<=n;j++)
			{
				if(a[i]<a[j])
				{
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			} 
		 
	} 
	int k;
	for(k=0;k<n;k++)
	{
		cout<<a[k];
	}
	return 0;
}
