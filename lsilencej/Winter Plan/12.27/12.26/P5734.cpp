#include<bits/stdc++.h>
using namespace std;
int main() {
	int q, n;
	scanf("%d", &q);
	string s;
	cin >> s;
	while (q--) {
		scanf("%d", &n);
		if (n == 1) {
			string a;
			cin >> a;
			s += a;
			cout << s << endl;
		}
		else if (n == 2) {
			int a, b;
			scanf("%d%d", &a, &b);
			s = s.substr(a, b);
			cout << s << endl;
		}
		else if (n == 3) {
			int a;
			string b;
			scanf("%d", &a);
			cin >> b;
			s.insert(a, b);
			cout << s << endl;
		}
		else if (n == 4) {
			string a;
			int b;
			cin >> a;
			b = s.find(a);
			cout << b << endl;
		}
	}
	return 0;
}
