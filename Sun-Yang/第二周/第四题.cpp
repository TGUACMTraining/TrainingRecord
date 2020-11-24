#include<iostream>
using namespace std;

int a[10000][10000],add[10000][10000];

int main()
{
	int T;int zuida=0;int zuidada=0;
	cin >> T;
	for(int TT=0;TT < T; TT ++)
	{
		int n,m,x,y;
		cin >> n >> m >> x >> y;
		
		for(int  i=1;i <= n;i ++)
		{
			for(int j=1;j <= m;j ++)
			{
					cin >> a[i][j];
					add[i][j]=add[i][j-1]+add[i-1][j]-add[i-1][j-1]+a[i][j];
			}
		}
		
		
		
		for(int i=0;i <=n-x;i ++)
		{
			for(int j=0;j<=m-y;j++)
			{
				zuidada=add[i+x][j+y]-add[i+x][j]-add[i][j+y]+add[i][j];//cout<<"zuidada="<<zuidada<<'\n';
				if(zuida<=zuidada) zuida=zuidada;zuidada=0;//cout<<zuidada;
			}
		}
		
		cout << zuida<<'\n';
		zuida=0;
	}
}
