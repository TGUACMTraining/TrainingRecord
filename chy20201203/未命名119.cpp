#include<iostream>
using namespace std;
int a[100001],b[100001];
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
    }
    int j,k,l;
    for(l=0;l<n;l++)
    {
    	int flag=0;
    	for(j=0;j<n;j++)
    	{
    		for(k=j+1;k<n;k++)
    		{
    			if(a[k]+a[j]==a[l])
    			{
    				flag=1;
				}
			}
		}
		ans+=flag;
	}
    cout<<ans;
	return 0;
}
