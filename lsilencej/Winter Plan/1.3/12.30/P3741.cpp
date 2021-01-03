#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, t = 0;
	scanf("%d", &n);
	string s;
	cin >> s;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'V' && s[i + 1] == 'K') {
			s[i] = s[i + 1] = 'X';
			t++;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'V') {
			if (s[i + 1] == 'V') {
				t++;
				break;
			}
		}
		else if (s[i] == 'K') {
			if (s[i + 1] == 'K') {
				t++;
				break;
			}
		}
	}
	printf("%d", t);
	return 0;
}
