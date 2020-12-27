#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, t = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (t < 10) printf("0%d", t++);
			else printf("%d", t++);
		}
		printf("\n");
	}
	printf("\n");
	t = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * n - i * 2; j++) {
			printf(" ");
		}
		for (int j = 1; j <= i; j++) {
			if (t < 10) printf("0%d", t++);
			else printf("%d", t++);
		}
		printf("\n");
	}
	return 0;
}
