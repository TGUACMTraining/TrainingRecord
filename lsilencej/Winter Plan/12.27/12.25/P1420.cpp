#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, t = 1, mmax = 1;
	int a[500];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1] + 1) t++;
		else {
			mmax = max(mmax, t);
			t = 1;
		}
	}
	printf("%d", mmax);
	return 0;
}
