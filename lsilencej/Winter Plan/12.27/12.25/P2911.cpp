#include<bits/stdc++.h>
using namespace std;
int a[100];
int main() {
	int x, y, z, mmax;
	scanf("%d%d%d", &x, &y, &z);
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <= z; k++) {
				a[i + j + k]++;
			}
		}
	}
	mmax = a[3];
	for (int i = 3; i <= x + y + z; i++) if (mmax < a[i]) mmax = a[i];
	for (int i = 3; i <= x + y + z; i++) {
		if (a[i] == mmax) {
			printf("%d", i);
			return 0;
		}
	}
	return 0;
}
