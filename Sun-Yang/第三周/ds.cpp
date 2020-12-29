#include<iostream>

using namespace std;

int n,count;
int a[1000],b[100][100];



void dfs(int x)
{
	
	bool xie(int x,int i);
	if(x == n)
	{
		for(int i = 1;i <= n;i ++)
		{
			if(b[x][i] == 0&&xie(x,i))
			{
				count ++;
				if(count <= 3)
				{
				
				a[x] = i;
				for(int i = 1 ; i <= n; i ++)
				cout << a[i] << " ";
				cout << '\n';
				}
				return ;
			}
		}
	}
	
	for(int i = 1;i <= n;i ++)
	{
		if(b[x][i] == 0&&xie(x,i))
		
		{
			if(count <= 3)
			a[x] = i;
			b[x][i] =1 ;
			dfs(x+1);
			b[x][i] = 0;
		}
	}
	
}


bool xie(int x,int i)
{
	int t = i -1,tt = i +1;
	for(int ii = x-1;ii > 0;ii --)
	{
		if(t>0)
		if(b[ii][t--] ==  1 ) return false ;
		if(tt <= n)
		if(b[ii][tt ++] == 1) return  false  ;
		if(b[ii][i] == 1) 
		return false ;    
	}
	
	
	
	int t1 = i -1 ,t2 = i + 1;
	for(int ii = x + 1;ii <= n;ii ++)
	{
		if(t1>0)
		if(b[ii][t1--]==1)return false;
		if(t2<=n)
		if(b[ii][t2 ++] == 1) return false;
}
return true;
	
}

int main()
{
	cin >> n;
	
	
	
	
	for(int i = 1;i <= n;i ++)
	{
		b[i][i] = 2,b[i][n+1-i] = 2;
		
		
		
	}
	
	dfs(1);cout << count;
	
}

