#include<bits/stdc++.h>
using namespace std;
int t,n;
string s[111];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>s[i];
		int flag1=0;
		for(int i=1;i<=n/2;i++)
		{
			int flag2=0;
			for(int j=0;j<s[i].length();j++)
			{
				for(int k=0;k<s[n-i+1].length();k++)
					if(s[i][j]==s[n-i+1][k])
						flag2=1;
			}
			if(!flag2)
			{
				cout<<"No\n";
				flag1=1;
				break;
			}
		}
		if(!flag1) cout<<"Yes\n";
	}
	return 0;
}
