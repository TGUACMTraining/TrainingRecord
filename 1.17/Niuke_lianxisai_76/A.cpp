#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100;
int n,tot,p;
int a[N];
string s;
bool Judge(int x)
{
	int flag=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=a[i];
		if(cnt==x) cnt=0;
		else if(cnt>x)
		{
			flag=1;
			break;
		}
	}
	if(!flag) return 1;
	else return 0;
}
int main()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		char c=getchar();
		a[i]=c-'0';
		tot+=a[i];
	}
	for(int i=n;i>1;i--)
		if(tot%i==0&&Judge(tot/i))
		{
			cout<<i;
			return 0;
		}
	cout<<"-1";
	return 0;
}
