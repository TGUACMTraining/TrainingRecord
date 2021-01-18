#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+100;
int t,n;
long long A,B;
long long a[N];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		A=B=0;
		int cnt=1;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=n;i>=1;i--)
		{
			if(cnt%2)
			{
				if(a[i]%2==0) A+=a[i];
			}
			else
			{
				if(a[i]%2==1) B+=a[i];
			}
			cnt++;
		}
		if(A>B) printf("Alice\n");
		else if(A<B) printf("Bob\n");
		else printf("Tie\n");
	}
	return 0;
}
