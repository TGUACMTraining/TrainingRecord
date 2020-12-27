#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	for (int j = 1; ; j++) {
		for (int i = 100; i >= 1; i--) {
			if ((52 * (7 * i + 21 * j)) == n) {
				printf("%d\n%d", i, j);
				return 0;
			}
		}
	}
	return 0;
}
