#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, t = 1;
	int a[100000];
	scanf("%d", &n);
	a[1] = n;
	while (n != 1) {
		if (n & 1) n = n * 3 + 1;
		else n /= 2;
		a[++t] = n;
	}
	for (int i = t; i >= 1; i--) printf("%d ", a[i]);
	return 0;
}
