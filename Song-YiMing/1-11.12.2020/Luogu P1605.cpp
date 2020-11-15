#include<cstdio>

using namespace std;
char mmp[11][11];
int st_x,st_y,ed_x,ed_y;
int dfs(int x,int y)
{
	if(mmp[x][y])return 0;					//Ë³ĞòºÜÖØÒª 
	else if(x==ed_x && y==ed_y)return 1;
	mmp[x][y]++;
	int tp=dfs(x+1,y)+dfs(x-1,y)+dfs(x,y+1)+dfs(x,y-1);
	mmp[x][y]--;
	return tp;
}
int main()
{
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=0;i<=6;i++)
	{
		mmp[0][i]=mmp[n+1][i]=2;
		mmp[i][0]=mmp[i][m+1]=2;
	}
	scanf("%d%d%d%d",&st_x,&st_y,&ed_x,&ed_y);
	for(int i=1;i<=t;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		mmp[x][y]=2;
	}
	printf("%d",dfs(st_x,st_y));
	return 0;
 } 
