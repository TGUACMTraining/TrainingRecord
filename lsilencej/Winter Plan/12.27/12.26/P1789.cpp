#include<bits/stdc++.h>
using namespace std;
int g[500][500];
int dx1[] = {2, 0, -2, 0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy1[] = {0, 2, 0, -2, 0, 1, -1, 1, 0, -1, 0, 1, -1};
int dx2[] = {-2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
int dy2[] = {-2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2};
int main() {
	int n, m, k, t = 0;
	scanf("%d%d%d", &n, &m, &k);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x][y] = 1;
		for (int i = 0; i <= 12; i++) {
			int dx = x + dx1[i];
			int dy = y + dy1[i];
			if (dx >= 1 && dx <= n && dy >= 1 && dy <= n && !g[dx][dy]) g[dx][dy] = 1;
		}
	}
	while (k--) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x][y] = 1;
		for (int i = 0; i <= 24; i++) {
			int dx = x + dx2[i];
			int dy = y + dy2[i];
			if (dx >= 1 && dx <= n && dy >= 1 && dy <= n && !g[dx][dy]) g[dx][dy] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!g[i][j]) t++;
		}
	}
	printf("%d", t);
	return 0;
}
