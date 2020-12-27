#include<bits/stdc++.h>
using namespace std;
int main() {
	int m, n, mmin = 0, sum;
	int a[5000];
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) mmin += a[i];
	for (int i = 1; i <= m - n + 1; i++) {
		sum = 0;
		for (int j = i; j <= n + i - 1; j++) sum += a[j];
		if (sum < mmin) mmin = sum;
	}
	printf("%d", mmin);
	return 0;
}
