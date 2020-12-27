#include<bits/stdc++.h>
using namespace std;
int main() {
	int t = 0;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a') t++;
		else if (s[i] == 'b') t += 2;
		else if (s[i] == 'c') t += 3;
		else if (s[i] == 'd') t++;
		else if (s[i] == 'e') t += 2;
		else if (s[i] == 'f') t += 3;
		else if (s[i] == 'g') t++;
		else if (s[i] == 'h') t += 2;
		else if (s[i] == 'i') t += 3;
		else if (s[i] == 'j') t++;
		else if (s[i] == 'k') t += 2;
		else if (s[i] == 'l') t += 3;
		else if (s[i] == 'm') t++;
		else if (s[i] == 'n') t += 2;
		else if (s[i] == 'o') t += 3;
		else if (s[i] == 'p') t++;
		else if (s[i] == 'q') t += 2;
		else if (s[i] == 'r') t += 3;
		else if (s[i] == 's') t += 4;
		else if (s[i] == 't') t++;
		else if (s[i] == 'u') t += 2;
		else if (s[i] == 'v') t += 3;
		else if (s[i] == 'w') t++;
		else if (s[i] == 'x') t += 2;
		else if (s[i] == 'y') t += 3;
		else if (s[i] == 'z') t += 4;
		else if (s[i] == ' ') t++;
	}
	printf("%d", t);
	return 0;
}
