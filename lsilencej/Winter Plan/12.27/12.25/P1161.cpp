#include<bits/stdc++.h>
using namespace std;
int l[2000000];
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		double a;
		int t;
		scanf("%lf%d", &a, &t);
		for (int i = 1; i <= t; i++) {
			if (l[(int)(a * i)]) l[(int)(a * i)] = 0;
			else l[(int)(a * i)] = 1;
		}
	}
	for (int i = 1; i <= 2000000; i++) {
		if (l[i] == 1) {
			printf("%d", i);
			return 0;
		}
	}
	return 0;
}
