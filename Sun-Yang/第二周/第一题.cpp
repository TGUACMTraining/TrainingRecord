#include<iostream>
using namespace std;

int n;
int tu[100][100];
int k[5] = {0,1,0,-1,0};	int a[300][300];int v[300][300];

 struct node
{
	int xx;
	int yy;
 } ;
 
 node que;



node q[100];int head = 0;int tail = -1;


bool check2(int x,int y)//延申检查0 
{
	
	
	
	if(x>=0&&x<n&&y>=0&&y<n)
	{
		if(a[x][y] == 0 && v[x][y] == 0)
		{return true;
		}
		else 
		{	return false; 
		}
	
	}
	else 
	{return false;
	}
}
bool check1(int x,int y)//检查是否为边界 
{
	
	
	
	if(x==0||y==0||x==n - 1 || y == n - 1)
	{
		if(a[x][y] == 0 && v[x][y] == 0)
		{return true;
		}
		else 
		{	return false; 
		}
	
	}
	else 
	{return false;
	}
	
}


void bfs(int x,int y)

{
	v[x][y] == 1; 
	que.xx = x,que.yy = y;
	tail++;
	q[tail] = que;
	while(head<=tail)
	{
		que = q[head];
		head ++;
		for(int i = 0; i<4;i++)
		{	
			
			int t1 = que.xx + k[i];
			int t2 = que.yy + k[i + 1];
			
			
			if(check2(t1,t2))
			{node t;
				
				
				t.xx = t1,t.yy=t2;
				
				q[++tail] = t;
				v[t1][t2]=1;
			}
		}
		
	}
}







int main()
{
	cin >> n;
	
	/*int a[n][n];int v[n][n] = {0};*/
		
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			cin >> a[i][j];
		}
	}//输入地图 
	for(int i = 0 ;i < n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(check1(i,j))
			{
				bfs(i,j);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(v[i][j] == 1) cout << "0 ";
			else if(a[i][j] == 0 &&v[i][j]==0) cout<< "2 ";
			else cout << "1 ";
		}
		if(i != n-1) cout << '\n';
	}
}
