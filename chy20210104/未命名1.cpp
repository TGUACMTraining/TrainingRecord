#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int n1;
	n1=n*n;
	int i=1,k,j,a=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
				if(a<=9)
				{
					cout<<'0'<<a;
					a++;
				}
				else
				{
					cout<<a;
					a++;
			    }
		}
		cout<<endl;
    }
	cout<<endl;
	int n2=2*n;
	int a1=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n2-2*i;j++)
		{
			cout<<" ";
		}
		for(j=1;j<=i;j++)
		{
			if(a1<=9)
		{
			cout<<'0'<<a1;
			a1++;
		}
		else
		{
			cout<<a1;
			a1++;
		}
		}
		cout<<endl;
	}
	return 0;
}
