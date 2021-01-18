#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
int t,n,ans;
int a[N],b[N];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=n;i>=1;i--)
		{
			if(i+a[i]<=n) b[i]=a[i]+b[i+a[i]];
			else b[i]=a[i];
			ans=max(b[i],ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
