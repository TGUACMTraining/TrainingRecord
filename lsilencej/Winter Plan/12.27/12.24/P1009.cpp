#include<bits/stdc++.h>
using namespace std;
long long f[120000], c[100][1000];
int main() {
	int n, len, nel;
	scanf("%d", &n);
	c[1][1] = 1;
	len = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= len; j++) c[i][j] = c[i - 1][j] * i;
		for (int j = 1; j <= len; j++) {
			if (c[i][j] >= 10) {
				c[i][j + 1] += c[i][j] / 10;
				c[i][j] %= 10;
			}
			if (c[i][len + 1]) len++;
		}
	}
	nel = len;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= len; j++) f[j] += c[i][j];
		for (int i = 1; i <= nel; i++) {
			if (f[i] >= 10) {
				f[i + 1] += f[i] / 10;
				f[i] %= 10;
			}
			while (f[nel + 1]) {
				nel++;
				f[nel + 1] += f[nel] / 10;
				f[nel] %= 10;
			}
		}
	}
	for (int i = nel; i >= 1; i--) printf("%lld", f[i]);
	return 0;
}
