#include<bits/stdc++.h>
using namespace std;
int x[200];
int main() {
	int n, key = 1, flag = 1;
	scanf("%d", &n);
	for (int i = n; i >= 0; i--) scanf("%d", &x[i]);
	for (int i = n; i >= 0; i--) {
		if (x[i] == 0 && key) continue;
		key = 0;
		if (flag) {
			if (x[i] == 1) printf("x^%d", i);
			else if (x[i] == -1) printf("-x^%d", i);
			else printf("%dx^%d", x[i], i);
			flag = 0;
			continue;
		}
		if (i == 0) {
			if (x[i] > 0) printf("+%d", x[i]);
			else if (x[i] < 0)printf("%d", x[i]);
		}
		else if (i == 1) {
			if (x[i] > 0) {
				if (x[i] == 1) printf("+x");
				else printf("+%dx", x[i]);
			} else if (x[i] < 0) {
				if (x[i] == -1) printf("-x");
				else printf("%dx", x[i]);
			}
		} 
		else {
			if (x[i] > 0) {
				if (x[i] == 1) printf("+x^%d", i);
				else printf("+%dx^%d", x[i], i);
			} else if (x[i] < 0) {
				if (x[i] == -1) printf("-x^%d", i);
				else printf("%dx^%d", x[i], i);
			}
		}
	}
	return 0;
}
