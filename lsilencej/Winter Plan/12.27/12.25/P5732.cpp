#include<bits/stdc++.h>
using namespace std;
int g[50][1000];
int main() {
	int n;
	scanf("%d", &n);
	g[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			g[i][j] = g[i - 1][j - 1] + g[i - 1][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d ", g[i][j]); 
		}
		printf("\n");
	}
	return 0;
}
