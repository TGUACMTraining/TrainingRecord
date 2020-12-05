#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
int xx[]={0,0,1,-1};
int yy[]={1,-1,0,0};
int mp[10001][10001];
bool vis[10001][10001];
int main()
{
	int i,j,k,sum=0;
	int x1,y1,x2,y2,t;
	cin>>x1>>y1>>x2>>y2>>t;
	for(i=1;i<=1000;i++)
	{
		for(j=1;j<=1000;j++)
		{
			mp[i][j]=0;
		}
	}
	queue<int>qx;
	queue<int>qy;
	qx.push(x1);
	qy.push(y1);
	queue<int>qxx;
	queue<int>qyy;
	qxx.push(x2);
	qyy.push(y2);
	int tzhen=0;
	while(tzhen<=t&&qx.empty()!=true&&qy.empty()!=true&&qxx.empty()!=true&&qyy.empty()!=true)
	{
		for(k=0;k<4;k++)
		{
			if(vis[qx.front()+xx[k]][qy.front()+yy[k]]==0&&qx.front()+xx[k]>0&&qx.front()+xx[k]<1000&&qy.front()+yy[k]>0&&qy.front()+yy[k]<1000&&mp[qx.front()+xx[k]][qy.front()+yy[k]]==0)
			{
				qx.push(qx.front()+xx[k]);
				qy.push(qy.front()+yy[k]);
				vis[qx.front()+xx[k]][qy.front()+yy[k]]=1;
				mp[qx.front()+xx[k]][qy.front()+yy[k]]==1;
				sum++;
			}
			else if(vis[qxx.front()+xx[k]][qyy.front()+yy[k]]==0&&qxx.front()+xx[k]>0&&qxx.front()+xx[k]<1000&&qyy.front()+yy[k]>0&&qyy.front()+yy[k]<1000&&mp[qx.front()+xx[k]][qy.front()+yy[k]]==0)
			{
				qxx.push(qxx.front()+xx[k]);
				qyy.push(qyy.front()+yy[k]);
				mp[qx.front()+xx[k]][qy.front()+yy[k]]==1;
				vis[qxx.front()+xx[k]][qyy.front()+yy[k]]=1;
				sum++;
		    }
		}
		qx.pop();
		qy.pop();
		qxx.pop();
		qyy.pop();
		tzhen++;
	}
	cout<<sum;
	return 0;
}
