#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int p;
int ans[N],temp[N];
void mul(int x[],int y[])
{
	int z[N]={0};
	for(int i=1;i<=500;i++)
		for(int j=1;j<=500;j++)
			z[i+j-1]+=x[i]*y[j];
	for(int i=1;i<=500;i++)
		z[i+1]+=z[i]/10,z[i]%=10;
	for(int i=1;i<=500;i++)
		x[i]=z[i];
}
void qsm()
{
	ans[1]=1;
	temp[1]=2;
	while(p)
	{
		if(p%2) mul(ans,temp);
		mul(temp,temp);
		p/=2;
	}
}
int main()
{
	cin>>p;
	printf("%d\n",(int)(log10(2)*p+1));
	qsm();
	ans[1]--;
	int cnt=0;
	for(int i=500;i>=1;i--)
	{
	    cout<<ans[i];
	    cnt++;
	    if(cnt==50) printf("\n"),cnt=0;
	}
	return 0;
}
