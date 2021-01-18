#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,ans;
ll x,y;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		if(x==0||x==1||y==0)
		{
			cout<<"-1\n";
			continue;
		}
		if(y==1||x>y)
		{
			cout<<"0\n";
			continue;
		}
		ll now=1;
		for(int i=1;i;i++)
		{
			now*=x;
			if(y/now<x)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
