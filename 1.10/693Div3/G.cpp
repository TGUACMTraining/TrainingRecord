/*
spfa求出最短路d[i]
初始f[i]=d[i]
以d[i]从大到小枚举节点 
若d[u]<d[v]则有f[u]=min(f[u],f[v])
若d[u]>=d[v]则有f[u]=min(f[u],d[v])  v只能往上 最小只能是d[v] 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+100;
int t,n,m;
int d[N],f[N],vis[N];
vector<int>e[N],a[N];
queue<int>q;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<=n;i++)
			e[i].clear(),a[i].clear();
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
		}
		memset(vis,0,sizeof(vis));
		memset(d,0x7f,sizeof(d));
		d[1]=0; vis[1]=1; q.push(1);
		while(q.size())
		{
			int u=q.front();
			q.pop(); a[d[u]].push_back(u);
			for(int i=0;i<e[u].size();i++)
			{
				int v=e[u][i];
				if(d[v]>d[u]+1)
				{
					d[v]=d[u]+1;
					if(!vis[v]) q.push(v),vis[v]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
			f[i]=d[i];
		for(int i=n-1;i>0;i--)
		{
			for(int j=0;j<a[i].size();j++)
			{
				int u=a[i][j];
				for(int k=0;k<e[u].size();k++)
				{
					int v=e[u][k];
					if(d[u]<d[v]) f[u]=min(f[u],f[v]);
					else f[u]=min(f[u],d[v]);
				}
			}
		}
		for(int i=1;i<=n;i++)
			cout<<f[i]<<" ";
		cout<<endl;
	}
	return 0;
}
