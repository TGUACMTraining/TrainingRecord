#include<bits/stdc++.h>
using namespace std;
int ans,tc=1,tf=1,flag;
int cx,cy,fx,fy;
int d[5][2]={0,0,-1,0,0,1,1,0,0,-1};
int v[11][11][11][11][5][5];
char c[11][11];
int main()
{
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
		{
			scanf(" %c",&c[i][j]);
			if(c[i][j]=='C') cx=i,cy=j;
			if(c[i][j]=='F') fx=i,fy=j;
		}
	v[cx][cy][fx][fy][tc][tf]=1;
	for(int i=1;i<=10;i++)
		c[i][0]=c[0][i]=c[i][11]=c[11][i]='*';
	while(cx!=fx||cy!=fy)
	{
		ans++;
		int tcx=cx+d[tc][0],tcy=cy+d[tc][1];
		int tfx=fx+d[tf][0],tfy=fy+d[tf][1];
		if(c[tcx][tcy]=='*') tc=tc%4+1;
		else cx=tcx,cy=tcy;
		if(c[tfx][tfy]=='*') tf=tf%4+1;
		else fx=tfx,fy=tfy;
		if(v[cx][cy][fx][fy][tc][tf])
		{
			flag=1;
			ans=0;
			break;
		}
		v[cx][cy][fx][fy][tc][tf]=1;
	}
	cout<<ans;
	return 0;
}
