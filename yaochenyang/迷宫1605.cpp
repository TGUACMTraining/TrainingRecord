#include<iostream>
using namespace std;
#define N 1000
int map[N][N]={0},v[N][N]={0};
int n,m,t,sx,sy,fx,fy,ans=0;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y)
{
	int tx,ty; 
	if(x==fx&&y==fy)
	{
		ans++;
		return;	
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			tx=x+dx[i];
			ty=y+dy[i];
			if(tx<1||ty<1||tx>n||ty>m)
				continue;
			else if(map[tx][ty]==0&&v[tx][ty]==0)
			{
				v[tx][ty]=1;
				dfs(tx,ty);
				v[tx][ty]=0;
			}
		}
	}
	return;
}
int main()
{
	int a,b;
	cin>>n>>m>>t;
	cin>>sx>>sy>>fx>>fy;
	while(t--)
	{
		cin>>a>>b;
		map[a][b]=2;
	}
	map[fx][fy]=1;
	dfs(fx,fy);
	cout<<ans<<endl;
	return 0;
}
