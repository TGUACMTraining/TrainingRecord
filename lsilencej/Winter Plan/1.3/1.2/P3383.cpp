#include<bits/stdc++.h>
using namespace std;
int vis[100000005];
int prime[100000005];
int main() {
	int n, cnt = 0, t = 0, nn;
	scanf("%d", &n);
	scanf("%d", &nn);
	for (int i = 2; i < n; i++) {
		if (!vis[i]) prime[cnt++] = i;
		for (int j = 0; j < cnt && i * prime[j] < n; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	for (int i = 1; i <= nn; i++) {
		int nu;
		scanf("%d", &nu);
		printf("%d\n", prime[nu - 1]);
	}
	return 0;
}
