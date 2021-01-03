#include<bits/stdc++.h>
using namespace std;
int a[27];
int main() {
	int mmax = -99999;
	for (int i = 1; i <= 4; i++) {
		string s;
		getline(cin, s);
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				a[s[i] - 'A' + 1]++;
				if (mmax < a[s[i] - 'A' + 1]) mmax = a[s[i] - 'A' + 1];
			}
		}
	}
	while (mmax) {
		for (int i = 1; i <= 26; i++) {
			if (a[i] == mmax) {
				printf("*");
				a[i]--;
			}
			else printf(" ");
			if (i != 26) printf(" ");
		}
		printf("\n");
		mmax--;
	}
	for (int i = 0; i < 26; i++) {
		printf("%c", i + 'A');
		if (i != 26) printf(" ");
	}
	return 0;
}
