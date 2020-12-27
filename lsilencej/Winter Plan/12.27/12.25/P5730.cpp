#include<bits/stdc++.h>
using namespace std;
char a[200];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (a[i] == '0') printf("XXX");
		else if (a[i] == '1') printf("..X");
		else if (a[i] == '2') printf("XXX");
		else if (a[i] == '3') printf("XXX");
		else if (a[i] == '4') printf("X.X");
		else if (a[i] == '5') printf("XXX");
		else if (a[i] == '6') printf("XXX");
		else if (a[i] == '7') printf("XXX");
		else if (a[i] == '8') printf("XXX");
		else if (a[i] == '9') printf("XXX");
		if (i != n) printf(".");
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		if (a[i] == '0') printf("X.X");
		else if (a[i] == '1') printf("..X");
		else if (a[i] == '2') printf("..X");
		else if (a[i] == '3') printf("..X");
		else if (a[i] == '4') printf("X.X");
		else if (a[i] == '5') printf("X..");
		else if (a[i] == '6') printf("X..");
		else if (a[i] == '7') printf("..X");
		else if (a[i] == '8') printf("X.X");
		else if (a[i] == '9') printf("X.X");
		if (i != n) printf(".");
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		if (a[i] == '0') printf("X.X");
		else if (a[i] == '1') printf("..X");
		else if (a[i] == '2') printf("XXX");
		else if (a[i] == '3') printf("XXX");
		else if (a[i] == '4') printf("XXX");
		else if (a[i] == '5') printf("XXX");
		else if (a[i] == '6') printf("XXX");
		else if (a[i] == '7') printf("..X");
		else if (a[i] == '8') printf("XXX");
		else if (a[i] == '9') printf("XXX");
		if (i != n) printf(".");
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		if (a[i] == '0') printf("X.X");
		else if (a[i] == '1') printf("..X");
		else if (a[i] == '2') printf("X..");
		else if (a[i] == '3') printf("..X");
		else if (a[i] == '4') printf("..X");
		else if (a[i] == '5') printf("..X");
		else if (a[i] == '6') printf("X.X");
		else if (a[i] == '7') printf("..X");
		else if (a[i] == '8') printf("X.X");
		else if (a[i] == '9') printf("..X");
		if (i != n) printf(".");
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		if (a[i] == '0') printf("XXX");
		else if (a[i] == '1') printf("..X");
		else if (a[i] == '2') printf("XXX");
		else if (a[i] == '3') printf("XXX");
		else if (a[i] == '4') printf("..X");
		else if (a[i] == '5') printf("XXX");
		else if (a[i] == '6') printf("XXX");
		else if (a[i] == '7') printf("..X");
		else if (a[i] == '8') printf("XXX");
		else if (a[i] == '9') printf("XXX");
		if (i != n) printf(".");
	}
	return 0;
}
