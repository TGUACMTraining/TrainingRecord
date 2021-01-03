#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		string s;
		cin >> s;
		int t, key = 0, r = 0, c = 0, flag = 1;
		for (int i = 0; i < s.length(); i++) {
			if (isdigit(s[i])) {
				t = i;
				break;
			}
		}
		for (int i = t; i < s.length(); i++) {
			if (!isdigit(s[i])) {
				key = 1;
				break;
			}
		}
		if (key) {
			for (int i = t; i < s.length(); i++) {
				if (!isdigit(s[i])) {
					t = i + 1;
					break;
				}
				r = r * 10 + s[i] - '0';
			}
			for (int i = t; i < s.length(); i++) c = c * 10 + s[i] - '0';
			string res;
			while (c) {
				if (c % 26 == 0) res = 'Z' + res;
				else res = (char)('A' + c % 26 - 1) + res;
				c = c / 26 - !(c % 26);
			}
			cout << res << r << endl;
		}
		else {
			for (int i = s.length() - 1, p = 0; i >= 0; i--, p *= 26) {
				if (!isdigit(s[i]) && flag) {
					t = i + 1;
					flag = 0;
					p = 1;
				}
				c += p * (s[i] - 'A' + 1);
			}
			for (int i = t; i < s.length(); i++) r = r * 10 + s[i] - '0';
			cout << 'R' << r << 'C' << c << endl;
		}
	}
	return 0;
}
