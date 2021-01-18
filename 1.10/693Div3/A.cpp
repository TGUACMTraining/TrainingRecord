#include<bits/stdc++.h>
using namespace std;
int t,w,h,n;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>w>>h>>n;
		int x=0,y=0;
		while(w%2==0&&w)
		{
			x++;
			w>>=1;
		}
		while(h%2==0&&h)
		{
			y++;
			h>>=1;
		}
		if(pow(2,x+y)>=n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
