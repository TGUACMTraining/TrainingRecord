#include<cstdio>

using namespace std;
int arr[1001][1001]={0};
int main()
{
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++)
	{
		int n,m,x,y;
		scanf("%d%d%d%d",&m,&n,&x,&y);
		for(int i=1;i<=m;i++)
		{
			int pre=0;
			for(int j=1;j<=n;j++)
			{
				int tp;
				scanf("%d",&tp);
				pre+=tp;
				arr[i][j]=arr[i-1][j]+pre;
			}
		}
		int mmax=-1;
		for(int i=x;i<=m;i++)
		{
			for(int j=y;j<=n;j++)
			{
				int tp = arr[i][j]+arr[i-x][j-y]
						-arr[i-x][j]-arr[i][j-y];
				if(mmax<tp)
				{
					mmax = tp;
				}
			}
		}
		printf("%d\n",mmax);
	}
	return 0;
}
