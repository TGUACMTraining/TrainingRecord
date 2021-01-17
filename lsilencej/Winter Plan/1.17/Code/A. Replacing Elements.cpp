#include<bits/stdc++.h>
using namespace std;
int a[500];
int n, d;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int sum = 0, key = 0;
		scanf("%d%d", &n, &d);
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] > d) key = 1;
		}
		if (!key) printf("YES\n");
		else {
			while (1) {
				sort(a + 1, a + 1 + n);
				if (a[n] <= d) {
					printf("YES\n");
					break;
				}
				a[n] = a[1] + a[2];
				if (a[n] > d) {
					printf("NO\n");
					break;
				}
			}
		}
	}
	return 0;
}
