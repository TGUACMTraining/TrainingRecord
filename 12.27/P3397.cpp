#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
int b[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		b[x1][y1]++; b[x1][y2+1]--;
		b[x2+1][y1]--; b[x2+1][y2+1]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
		{
			b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
			printf("%d ",b[i][j]);
		}
		b[i][n]+=b[i-1][n]+b[i][n-1]-b[i-1][n-1];
		printf("%d\n",b[i][n]);
	}
	return 0;
}
