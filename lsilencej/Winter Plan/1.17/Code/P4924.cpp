#include<bits/stdc++.h>
using namespace std;
int g[1000][1000], gg[1000][1000];
int main() {
	int n, t = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = t++;
			gg[i][j] = g[i][j];
		}
	}
	int m;
	scanf("%d", &m);
	while (m--) {
		int x, y, r, z;
		scanf("%d%d%d%d", &x, &y, &r, &z);
		if (z == 0) {
			int xx = x - r, yy = y - r;
			for (int i = y - r; i <= y + r; i++) {
				for (int j = x + r; j >= x - r; j--) {
					gg[xx][yy++] = g[j][i];
				}
				yy = y - r;
				xx++;
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					g[i][j] = gg[i][j];
				}
			}
		}
		else {
			int xx = x - r, yy = y - r;
			for (int i = y + r; i >= y - r; i--) {
				for (int j = x - r; j <= x + r; j++) {
					gg[xx][yy++] = g[j][i];
				}
				yy = y - r;
				xx++;
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					g[i][j] = gg[i][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
	return 0;
}
