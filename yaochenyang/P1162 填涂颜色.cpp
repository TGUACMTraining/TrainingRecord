#include<iostream>
#include<cstdio>
using namespace std;
int a[100][100],b[100][100]={0};
int x,y,n;

void dfs(int x,int y)
{
	if(x>n||x<1||y>n||y<1||a[x][y]!=0)
	return;
	a[x][y]=1;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y-1);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1)
			b[i][j]=-1;	
		}	
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(a[1][i]!=1) 
		dfs(1,i);
		if(a[n][i]!=1)
		dfs(n,i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[i][j]==-1)
			cout<<1<<" ";
			else if(a[i][j]==0)
			cout<<2<<" ";
			else cout<<0<<" ";
		}
		cout<<endl;
	}
	return 0;
}
