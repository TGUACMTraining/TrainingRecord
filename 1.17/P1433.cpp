#include<bits/stdc++.h>
using namespace std;
const int N=20;
const int M=35000;
int n;
double ans=100000000;
double x[N],y[N],d[N][N],f[N][M];
double dis(int i,int j)
{
	return sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	memset(f,127,sizeof(f));
	for(int s=1;s<(1<<n);s++)
		for(int i=1;i<=n;i++)
		{
			if((s&(1<<(i-1)))==0) continue;
			if(s==(1<<(i-1)))
			{
				f[i][s]=0;
				continue;
			}
			for(int j=1;j<=n;j++)
			{
				if((s&(1<<(j-1)))==0||i==j) continue;
				f[i][s]=min(f[i][s],f[j][s-(1<<(i-1))]+dis(i,j));
			}
		}
	for(int i=1;i<=n;i++)
	{
		double s=dis(0,i)+f[i][(1<<n)-1];
		ans=min(ans,s);
	}
	printf("%.2f",ans);
	return 0;
}
