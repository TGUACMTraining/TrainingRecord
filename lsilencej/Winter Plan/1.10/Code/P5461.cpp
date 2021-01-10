#include<bits/stdc++.h>
using namespace std;
int g[2000][2000];
void she(int x, int y, int n) {
	if (n == 0) return;
	for (int i = x; i <= x + n - 1; i++) {
		for (int j = y; j <= y + n - 1; j++) {
			g[i][j] = 1;
		}
	}
	she(x, y + n, n / 2);
	she(x + n, y, n / 2);
	she(x + n, y + n, n / 2);
}
int main() {
	int n;
	scanf("%d", &n);
	she(1, 1, pow(2, n - 1));
	for (int i = 1; i <= pow(2, n); i++) {
		for (int j = 1; j <= pow(2, n); j++) {
			if (g[i][j]) printf("0 ");
			else printf("1 ");
		}
		printf("\n");
	}
	return 0;
}
