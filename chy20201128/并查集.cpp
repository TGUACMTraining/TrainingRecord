#include<bits/stdc++.h>
using namespace std;
int parent[10001];
int find(int x)
{
	if(parent[x]!=x)
	{
		return find(parent[x]);
	}
	else
	return x;
}
void union(int x,int y)
{
	parent[find(y)]=find(x);
	return ;
}
int main()
{
	int n,m,p,mi,mj;
	cin>>n>>m>>p;
	int i;
	for(i=1;i<=n;i++)
	{
		parent[i]=i;
	}
	for(int j=1;j<=m;j++)
	{
		cin>>mi>>mj;
		union(mi,mj);
	}
	int qi,qj;
	for(int j1=1;j1<=p;j1++)
	{
		cin>>qi>>qj;
		if(find(qi)==find(qj))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
