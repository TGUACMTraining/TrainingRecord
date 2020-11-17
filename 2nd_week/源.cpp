#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int a[32][32], b[32][32];
int xd[5] = { 0, -1, 1, 0, 0 };
int yd[5] = { 0, 0, 0, -1, 1 };
int n;

void dfs(int x, int y) {
	int i;
	if (x < 0 || x > n + 1 || y < 0 || y>n + 1 || a[x][y] != 0)return;
	a[x][y] = 1;
	for (i = 1; i <=4; i++) dfs(x + xd[i], y + yd[i]);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 0)
			{
				a[i][j] = 0;
			}
			else a[i][j] = 2;
		}

	}
	dfs(0, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (a[i][j] == 0) cout << 2 << ' ';
			else cout << b[i][j] << ' ';
		cout << '\n';
	}
	return 0;

}
