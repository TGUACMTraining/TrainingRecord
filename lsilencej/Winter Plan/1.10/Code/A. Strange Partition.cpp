#include<bits/stdc++.h>
using namespace std;
int a[200000];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n, x, aa, sum = 0;
		scanf("%lld%lld", &n, &x);
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		printf("%lld ", (long long)ceil((double)sum / x));
		sum = 0;
		for (int i = 1; i <= n; i++) sum += ceil((double)a[i] / x);
		printf("%lld\n", sum);
	}
	return 0;
}
