#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int main() {
	int n, t = 1, x = 1, y = 0;
	scanf("%d", &n);
	while (t <= n * n) {
		while (y < n && !a[x][y + 1]) a[x][++y] = t++;
		while (x < n && !a[x + 1][y]) a[++x][y] = t++;
		while (y > 1 && !a[x][y - 1]) a[x][--y] = t++;
		while (x > 1 && !a[x - 1][y]) a[--x][y] = t++;
	}
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
