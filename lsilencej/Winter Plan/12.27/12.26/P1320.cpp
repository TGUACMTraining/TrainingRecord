#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, t0 = 0, t1 = 0;
	string s;
	cin >> s;
	n = s.length();
	printf("%d ", n);
	if (s[0] == '1') printf("0 ");
	while (n--) {
		if (s[0] == '1') {
			if (t0) {
				printf("%d ", t0);
				t0 = 0;
			}
			t1++;
		}
		else {
			if (t1) {
				printf("%d ", t1);
				t1 = 0;
			}
			t0++;
		}
		for (int i = 1; i <= s.length() - 1; i++) {
			if (s[i] != s[i - 1]) {
				if (t0) {
					printf("%d ", t0);
					t0 = 0;
				} else {
					printf("%d ", t1);
					t1 = 0;
				}
			}
			if (s[i] == '1') t1++;
			else t0++;
		}
		if (n) cin >> s;
	}
	if (t0) printf("%d ", t0);
	else if (t1) printf("%d ", t1);
	return 0;
}
