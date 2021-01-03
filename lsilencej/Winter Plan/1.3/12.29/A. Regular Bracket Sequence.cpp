#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int z = 0, key = 0;
		string s;
		cin >> s;
		if ((s.length() & 1) || s[0] == ')' || s[s.length() - 1] == '(') {
			printf("NO\n");
			continue;
		}
		else printf("YES\n");
	}
	return 0;
}
