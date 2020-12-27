#include<bits/stdc++.h>
using namespace std;
long long a[1000];
int main() {
	int p;
	scanf("%d", &p);
	printf("%d\n", (int)ceil(p * log10(2)));
	a[500] = 1;
	long long t = pow(2, 32);
	int tt = p / 32;
	long long ttt = p - p / 32 * 32;
	for (int i = 1; i <= tt; i++) {
		for (int j = 500; j >= 1; j--) {
			a[j] *= t;
		}
		for (int j = 500; j >= 1; j--) {
			a[j - 1] += a[j] / 10;
			a[j] %= 10;
		}
	}
	for (int i = 1; i <= ttt; i++) {
		for (int j = 500; j >= 1; j--) {
			a[j] *= 2;
		}
		for (int j = 500; j >= 1; j--) {
			a[j - 1] += a[j] / 10;
			a[j] %= 10;
		}
	}
	a[500]--;
	for (int i = 1; i <= 500; i++) {
		printf("%d", a[i]);
		if (i % 50 == 0) printf("\n");
	}
	return 0;
}
