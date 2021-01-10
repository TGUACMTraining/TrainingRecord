#include<bits/stdc++.h>
using namespace std;
struct ll{
	long long z, c;
} a[200000], b[200000]; 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n, x, sum = 0;
		scanf("%lld%lld", &n, &x);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 1; i < 200000; i++) b[i].c = 1;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i].z);
			b[i].z = a[i].z;
			int key = 1;
			while (a[i].z % x == 0) {
				b[i].c++;
				a[i].z /= x;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (b[i].c) {
				sum += b[i].z;
				b[i].c--;
			}
			else break;
			if (i == n) i = 0;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
