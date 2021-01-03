#include<bits/stdc++.h>
using namespace std;
string s;
int meth(int k) {
	if (k == 1) {
		int key = 1;
		if (s[0] == '0') cout << 0;
		else {
			for (int i = s.length() - 1; i >= 0; i--) {
				if (s[i] == '0' && key) continue;
				key = 0;
				cout << s[i];
			}
		}
	} else if (k == 2) {
		int t;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '.') {
				t = i;
				break;
			}
		}
		int key = 1;
		if (s[0] == '0') cout << 0;
		else {
			for (int i = t - 1; i >= 0; i--) {
				if (s[i] == '0' && key) continue;
				key = 0;
				cout << s[i];
			}
		}
		cout << '.';
		key = 1;
		int tt = t;
		for (int i = t + 1; i < s.length(); i++) {
			if (s[i] == '0' && key) continue;
			key = 0;
			tt = i;
			break;
		}
		if (tt == t) cout << 0;
		else for (int i = s.length() - 1; i >= tt; i--) cout << s[i];
	} else if (k == 3) {
		int t;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '/') {
				t = i;
				break;
			}
		}
		int key = 1;
		if (s[0] == '0') cout << 0;
		else {
			for (int i = t - 1; i >= 0; i--) {
				if (s[i] == '0' && key) continue;
				key = 0;
				cout << s[i];
			}
		}
		key = 1;
		cout << '/';
		for (int i = s.length() - 1; i > t; i--) {
			if (s[i] == '0' && key) continue;
			key = 0;
			cout << s[i];
		}
	} else if (k == 4) {
		int key = 1;
		if (s[0] == '0') cout << 0;
		else {
			for (int i = s.length() - 2; i >= 0; i--) {
				if (s[i] == '0' && key) continue;
				key = 0;
				cout << s[i];
			}
		}
		cout << '%';
	}
}
int main() {
	cin >> s;
	int key = 0;
	for (int i = 0; i < s.length(); i++) {
		if (!isdigit(s[i])) {
			if (s[i] == '.') key = 2;
			else if (s[i] == '/') key = 3;
			else if (s[i] == '%') key = 4;
			break;
		}
		key = 1;
	}
	meth(key);
	return 0;
}
