#include<bits/stdc++.h>
using namespace std;
int g[1200][1200];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				g[i][j]++;
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
