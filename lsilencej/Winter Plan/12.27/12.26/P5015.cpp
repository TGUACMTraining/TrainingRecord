#include<bits/stdc++.h>
using namespace std;
int main() {
	int t = 0;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') continue;
		t++;
	}
	printf("%d", t);
	return 0;
}
