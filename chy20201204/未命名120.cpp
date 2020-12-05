#include<iostream>
using namespace std;
int main()
{
	int n;
	int a[n+10];
	cin>>n;
	int i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	a[0]=-1;
	int b=0,maxb=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]>a[i-1])
		{
			b++;
			if(b>maxb)
			{
				maxb=b;
			}
		}
		else
		{
			b=1;
		}
    }
    cout<<maxb;
	return 0;
}
