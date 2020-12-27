#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, x, y, num, sum;
	string s;
	char o;
	scanf("%d", &n);
	while (n--) {
		cin >> s;
		num = sum = 0;
		if (s[0] == 'a') {
			scanf("%d%d", &x, &y);
			sum = x + y;
			printf("%d+%d=%d\n", x, y, sum);
			if (x <= 0) num++;
			if (y <= 0) num++;
			if (sum <= 0) num++;
			while (x) {
				num++;
				x /= 10;
			}
			while (y) {
				num++;
				y /= 10;
			}
			while (sum) {
				num++;
				sum /= 10;
			}
			printf("%d\n", num + 2);
			o = 'a';
		} else if (s[0] == 'b') {
			scanf("%d%d", &x, &y);
			sum = x - y;
			printf("%d-%d=%d\n", x, y, sum);
			if (x <= 0) num++;
			if (y <= 0) num++;
			if (sum <= 0) num++;
			while (x) {
				num++;
				x /= 10;
			}
			while (y) {
				num++;
				y /= 10;
			}
			while (sum) {
				num++;
				sum /= 10;
			}
			printf("%d\n", num + 2);
			o = 'b';
		} else if (s[0] == 'c') {
			scanf("%d%d", &x, &y);
			sum = x * y;
			printf("%d*%d=%d\n", x, y, sum);
			if (x <= 0) num++;
			if (y <= 0) num++;
			if (sum <= 0) num++;
			while (x) {
				num++;
				x /= 10;
			}
			while (y) {
				num++;
				y /= 10;
			}
			while (sum) {
				num++;
				sum /= 10;
			}
			printf("%d\n", num + 2);
			o = 'c';
		} else {
			x = s[0] - '0';
			for (int i = 1; i <= s.length() - 1; i++) x = x * 10 + s[i] - '0';
			scanf("%d", &y);
			if (o == 'a') {
				sum = x + y;
				printf("%d+%d=%d\n", x, y, sum);
				if (x <= 0) num++;
				if (y <= 0) num++;
				if (sum <= 0) num++;
				while (x) {
					num++;
					x /= 10;
				}
				while (y) {
					num++;
					y /= 10;
				}
				while (sum) {
					num++;
					sum /= 10;
				}
				printf("%d\n", num + 2);
			} else if (o == 'b') {
				sum = x - y;
				printf("%d-%d=%d\n", x, y, sum);
				if (x <= 0) num++;
				if (y <= 0) num++;
				if (sum <= 0) num++;
				while (x) {
					num++;
					x /= 10;
				}
				while (y) {
					num++;
					y /= 10;
				}
				while (sum) {
					num++;
					sum /= 10;
				}
				printf("%d\n", num + 2);
			} else if (o == 'c') {
				sum = x * y;
				printf("%d*%d=%d\n", x, y, sum);
				if (x <= 0) num++;
				if (y <= 0) num++;
				if (sum <= 0) num++;
				while (x) {
					num++;
					x /= 10;
				}
				while (y) {
					num++;
					y /= 10;
				}
				while (sum) {
					num++;
					sum /= 10;
				}
				printf("%d\n", num + 2);
			}
		}
	}
	return 0;
}
