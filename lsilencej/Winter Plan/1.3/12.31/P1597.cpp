#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int a = 0, b = 0, c = 0;
	for (int i = 1; i < s.length(); i += 5) {
		if (s[i - 1] == 'a') {
			if (s[i + 2] >= '0' && s[i + 2] <= '9') a = s[i + 2] -'0';
			else if (s[i + 2] == 'b') a = b;
			else if (s[i + 2] == 'c') a = c;
		}
		else if (s[i - 1] == 'b') {
			if (s[i + 2] >= '0' && s[i + 2] <= '9') b = s[i + 2] -'0';
			else if (s[i + 2] == 'a') b = a;
			else if (s[i + 2] == 'c') b = c;
		}
		else if (s[i - 1] == 'c') {
			if (s[i + 2] >= '0' && s[i + 2] <= '9') c = s[i + 2] -'0';
			else if (s[i + 2] == 'a') c = a;
			else if (s[i + 2] == 'b') c = b;
		}
	}
	printf("%d %d %d", a, b, c);
	return 0;
}
