#include<bits/stdc++.h>
using namespace std;
long long a[120000], b[120000], c[120000];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) a[i] = a[i - 1] + i;
	for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
	for (int i = 1; i <= n; i++) c[i] = c[i - 1] + b[i];
	printf("%lld", c[n - 3]);
	return 0;
}
