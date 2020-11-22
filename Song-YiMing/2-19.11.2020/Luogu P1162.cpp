#include<cstdio>
#define YES 2
using namespace std;
int n,mmp[33][33]={0};
int cpy[33][33]={0}; 	//1notin 0undefined 

void ddfs(int x,int y)
{
	if(cpy[x][y] || mmp[x][y]==1
	|| x<0||x>n+1 || y<0||y>n+1)
	//ÖØ¸´ ×²Ç½ Ô½½ç 
	return;
	cpy[x][y]=YES;
	ddfs(x+1,y);ddfs(x-1,y);
	ddfs(x,y+1);ddfs(x,y-1);
}
int main()
{
	scanf("%d",&n);
	int x,y;bool b=1; 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&mmp[i][j]);
			cpy[i][j]=mmp[i][j];
			if(b){
				if(!mmp[i][j]){
					x=i;y=j;
					b=0;
				}
			}
		}
	}
	ddfs(x,y);
	bool yes;
	if(cpy[0][0]==YES){
		yes=0;
	}else{
		yes=1;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(cpy[i][j]==yes*YES){
				printf("2 ");
			}else printf("%d ",mmp[i][j]);
		}
		if(cpy[i][n]==yes*YES){
			printf("2\n");
		}else printf("%d\n",mmp[i][n]);
	}
	
	return 0;
 } 
