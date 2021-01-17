#include<bits/stdc++.h>
using namespace std;
char a[1000], b[1000];
int c[1000], d[1000], e[2000];
int main() {
	cin >> a >> b;
	int ta, tb, tta = 0, ttb = 0, len;
	ta = strlen(a);
	tb = strlen(b);
	for (int i = ta - 1; i >= 0; i--) c[tta++] = a[i] - '0';
	for (int i = tb - 1; i >= 0; i--) d[ttb++] = b[i] - '0';
	for (int i = 0; i <= max(ta, tb) - 1; i++) {
		e[i] += c[i] + d[i];
		if (e[i] > 9) {
			e[i + 1] += (e[i] / 10);
			e[i] %= 10;
		}
	}
	len = max(ta, tb);
	while (e[len] > 9) {
		e[len + 1] += (e[len] / 10);
		e[len++] %= 10;
	}
	if (e[len] == 0) for (int i = len - 1; i >= 0; i--) printf("%d", e[i]);
	else for (int i = len; i >= 0; i--) printf("%d", e[i]);
	return 0;
}
