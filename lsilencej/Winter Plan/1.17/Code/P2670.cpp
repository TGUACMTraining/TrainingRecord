#include<bits/stdc++.h>
using namespace std;
int g[500][500], gg[500][500];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == '*') g[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			gg[i][j] = g[i - 1][j] + g[i + 1][j] + g[i - 1][j - 1] + g[i - 1][j + 1] + g[i + 1][j + 1] + g[i + 1][j - 1] + g[i][j - 1] + g[i][j + 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (g[i][j] == 1) printf("*");
			else printf("%d", gg[i][j]);
		}
		printf("\n");
	}
	return 0;
}
