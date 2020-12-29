#include<iostream>

using namespace std;

int N,M;
char  s[200][200];

int search(char x,int t1,int t2)
{
	int count = 0;
	for(int i = t1; i <= t2; i ++)
	{
		for(int j = 0;j < M ; j ++)
		{
			if(s[i][j] != x) count ++;}}return count;
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i ++)
	{
		for(int j = 0 ;j < M;j ++)
		{
			scanf(" %c",&s[i][j]);
		}
	}
	int count = 1000;
	for(int i = N-3;i >= 0 ; i --)
	{
		for(int t = N - 2;t > i; t --)
		{
			
			int count1 = search( 'W',0,i) + search( 'B',i+1,t) + search ('R',t+1,N-1);
			if(count1 < count) count = count1;
		}
	}
	cout << count;
	
	
}
