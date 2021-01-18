/*
分类讨论

map迭代器遍历： 
	map<int,int>::iterator a;
	for(a=mp.begin();a!=mp.end();a++)
	a->first表下标  a->second表值 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int t,n,m,x,y;
map<int,int>mp;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		mp.clear();
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y;
			mp[y]|=1<<(x-1);
		}
		int lastl=0,flag=0,lastr=0;
		map<int,int>::iterator a;
		for(a=mp.begin();a!=mp.end();a++)
		{
			if(a->second!=3&&lastl)
			{
				if(a->second==lastl)
				{
					if((a->first-lastr-1)%2) flag=1;
					else lastl=0,lastr=a->first;
				}
				else
				{
					if((a->first-lastr-1)%2==0) flag=1;
					else lastl=0,lastr=a->first;
				}
			}
			else if(a->second!=3) lastl=a->second,lastr=a->first;
			else if(a->second==3&&lastl) flag=1;
		}
		if(lastl) flag=1;
		if(flag) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
