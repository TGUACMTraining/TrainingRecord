#include<bits/stdc++.h>
using namespace std;
int g[500][500];
int main() {
	int n, x = 1, y = 1, t, key = 1;
	scanf("%d", &n);
	while (x * y <= n * n) {
		scanf("%d", &t);
		if (key) key = 0;
		else key = 1;
		while (t--) {
			if (y == n + 1) {
				x++;
				y = 1;
			}
			if (key) g[x][y++] = 1;
			else g[x][y++] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			 printf("%d", g[i][j]);
		}
		printf("\n");
	}
	return 0;
}
