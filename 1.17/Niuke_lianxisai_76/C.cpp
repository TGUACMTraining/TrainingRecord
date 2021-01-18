#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
int t;
ll n,m;
ll qpow(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y%2) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
        ll mul=m*(m-1)/2*3%mod;
        ll A=qpow(m,n-2);
        cout<<A*mul%mod*(n-1)%mod<<endl;
	}
	return 0;
}
