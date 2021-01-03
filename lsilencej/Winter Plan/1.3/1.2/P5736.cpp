#include<bits/stdc++.h>
using namespace std;
int vis[300000];
int prime[300000];
int num[300000];
int a[500];
int main() {
	int n, cnt = 0, t = 0;
	scanf("%d", &n);
	for (int i = 2; i < 100000; i++) {
		if (!vis[i]) {
			prime[cnt++] = i;
			num[i] = 1;
		}
		for (int j = 0; j < cnt && i * prime[j] < 100000; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	for (int i = 1; i <= n; i++) {
		int nu;
		scanf("%d", &nu);
		if (num[nu]) a[t++] = nu;
	}
	for (int i = 0; i < t; i++) printf("%d ", a[i]);
	return 0;
}
