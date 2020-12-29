#include<iostream>

using namespace std;

int a[6000][6000];
void f(int n)
{
	int i = 3;
	for(;i <= n;i++)
	{
		
		 int j = 1;
		 int jinwei = 0;
		 for(;j < 6000;j ++)
		 {
		 	a[i][j] = ((a[i-1][j]+a[i-2][j]) + jinwei) % 10;
			jinwei = ((a[i-1][j]+a[i-2][j]) + jinwei) / 10;
		 }
	}
	
}
int main()
{
	
	int n;
	cin >> n;
	a[1][1] = 1,a[2][1] = 2;f(n);
	int k = 6000;
	for(;k > 0;k --)
	{
		if(a[n][k] != 0) break;
	}
	for(k;k >0;k  --) cout << a[n][k];
	if(n == 0) cout << "0";
}
