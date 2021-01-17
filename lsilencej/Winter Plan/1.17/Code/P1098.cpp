#include<bits/stdc++.h>
using namespace std;
int main() {
	int p1, p2, p3;
	scanf("%d%d%d", &p1, &p2, &p3);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') {
			char a, b;
			a = s[i - 1];
			b = s[i + 1];
			if (b > a && ((a >= '0' && a <= '9' && b >= '0' && b <= '9') || (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z'))) {
				i++;
				if (p3 == 1) {
					if (p1 == 1) {
						for (int j = 1; j <= b - a - 1; j++) {
							for (int k = 1; k <= p2; k++) {
								cout << (char)(a + j);
							}
						}
					} else if (p1 == 2) {
						if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') {
							a = a - 'a' + 'A';
							b = b - 'a' + 'A';
							for (int j = 1; j <= b - a - 1; j++) {
								for (int k = 1; k <= p2; k++) {
									cout << (char)(a + j);
								}
							}
						} else {
							for (int j = 1; j <= b - a - 1; j++) {
								for (int k = 1; k <= p2; k++) {
									cout << (char)(a + j);
								}
							}
						}
					} else if (p1 == 3) {
						for (int j = 1; j <= b - a - 1; j++) {
							for (int k = 1; k <= p2; k++) {
								cout << '*';
							}
						}
					}
				} else {
					if (p1 == 1) {
						for (int j = 1; j <= b - a - 1; j++) {
							for (int k = 1; k <= p2; k++) {
								cout << (char)(b - j);
							}
						}
					} else if (p1 == 2) {
						if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') {
							a = a - 'a' + 'A';
							b = b - 'a' + 'A';
							for (int j = 1; j <= b - a - 1; j++) {
								for (int k = 1; k <= p2; k++) {
									cout << (char)(b - j);
								}
							}
						} else {
							for (int j = 1; j <= b - a - 1; j++) {
								for (int k = 1; k <= p2; k++) {
									cout << (char)(b - j);
								}
							}
						}
					} else if (p1 == 3) {
						for (int j = 1; j <= b - a - 1; j++) {
							for (int k = 1; k <= p2; k++) {
								cout << '*';
							}
						}
					}
				}
			}
		}
		cout << s[i];
	}
	return 0;
}
