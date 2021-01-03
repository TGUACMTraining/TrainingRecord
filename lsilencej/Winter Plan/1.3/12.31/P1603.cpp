#include<bits/stdc++.h>
using namespace std;
int cmp(string a, string b) {
	return a + b < b + a;
}
int main() {
	string s;
	string a[10];
	int t = 1;
	for (int i = 1; i <= 6; i++) {
		cin >> s;
		if (s == "one" || s == "a" || s == "another" || s == "first") a[t++] = "01";
		else if (s == "two" || s == "both" || s == "second") a[t++] = "04";
		else if (s == "three" || s == "third") a[t++] = "09";
		else if (s == "four") a[t++] = "16";
		else if (s == "five") a[t++] = "25";
		else if (s == "six") a[t++] = "36";
		else if (s == "seven") a[t++] = "49";
		else if (s == "eight") a[t++] = "64";
		else if (s == "nine") a[t++] = "81";
		else if (s == "ten") a[t++] = "00";
		else if (s == "eleven") a[t++] = "21";
		else if (s == "twelve") a[t++] = "44";
		else if (s == "thirteen") a[t++] = "69";
		else if (s == "fourteen") a[t++] = "96";
		else if (s == "fifteen") a[t++] = "25";
		else if (s == "sixteen") a[t++] = "56";
		else if (s == "seventeen") a[t++] = "89";
		else if (s == "eightteen") a[t++] = "24";
		else if (s == "nineteen") a[t++] = "61";
		else if (s == "twenty") a[t++] = "00";
	}
	if (t == 1) {
		printf("0");
		return 0;
	}
	sort(a + 1, a + t, cmp);
	int key = 1;
	for (int i = 1; i <= t - 1; i++) {
		for (int j = 0; j < a[i].length(); j++) {
			if (a[1][0] == '0' && key) {
				key = 0;
				continue;
			}
			cout << a[i][j];
		}
	}
	return 0;
}
