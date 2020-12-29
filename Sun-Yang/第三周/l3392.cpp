#include<iostream>

using namespace std;

char q[100][100];

int n,m;

int sear(int n,int i,char a)
{
	
	int count1 = 0;
	for(int k = i;k <= n;k ++)
	{
		for(int kk = 0;kk < m;kk ++)
		{
			if(q[k][kk] != a) count1 ++;
		}
	}
	return count1;
}
int main()
{
	
	cin >> n >> m;
	int sear(int n,int i,char a);
	for(int i=0;i<n;i ++)
	{
		for(int j=0;j< m ;j ++)
		{
			scanf(" %1c",&q[i][j]);
		}
	}
	
	int count=2500,count1;
		char a = 'W',b='B',c='R';
	for(int i = n - 3 ;i >= 0;i --)
	{
		
		
		for(int ii=n-2;ii > i;ii --)
		{
			count1 = sear(i,0,a) + sear(ii,i  +  1,b) + sear(n-1,ii+1,c);//cout<<"count1="<<count1;
			if(count1 < count) count = count1;
		}
		
	}
	cout << count;
 } 

