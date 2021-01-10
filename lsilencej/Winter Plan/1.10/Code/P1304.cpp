#include<bits/stdc++.h>
using namespace std;
int prime[20000];
int vis[20000];
int cnt = 1;
int main() {
	for (int i = 2; i <= 10000; i++) {
		if (!vis[i]) prime[cnt++] = i;
		for (int j = 1; j < cnt && i * prime[j] <= 10000; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
		
	}
	int n;
	scanf("%d", &n);
	for (int i = 4; i <= n; i += 2) {
		for (int j = 1; j < cnt; j++) {
			if (!vis[i - prime[j]]) {
				printf("%d=%d+%d\n", i, prime[j], i - prime[j]);
				break;	
			}
		}
	}
	return 0;
}
