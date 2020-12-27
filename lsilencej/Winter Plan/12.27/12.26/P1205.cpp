#include<bits/stdc++.h>
using namespace std;
int n, key = 1, flag = 1, ffl = 1;
char g[50][50], gg[50][50], ggg[50][50], gggg[50][50], ggggg[50][50], gggggg[50][50];
int jud() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (gg[i][j] != ggg[i][j]) return 0;
		}
	}
	return 1;
}
int dec(int k) {
	int x = 1, y = 1;
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = n; j >= 1; j--) {
				ggg[x][y++] = g[j][i];
			}
			x++;
			y = 1;
		}
		if (jud()) return 1;
		else return 0;
	} else if (k == 2) {
		for (int i = n; i >= 1; i--) {
			for (int j = n; j >= 1; j--) {
				ggg[x][y++] = g[i][j];
			}
			x++;
			y = 1;
		}
		if (jud()) return 1;
		else return 0;
	} else if (k == 3) {
		for (int i = n; i >= 1; i--) {
			for (int j = 1; j <= n; j++) {
				ggg[x][y++] = g[j][i];
			}
			x++;
			y = 1;
		}
		if (jud()) return 1;
		else return 0;
	} else if (k == 4) {
		for (int i = 1; i <= n; i++) {
			for (int j = n; j >= 1; j--) {
				ggg[x][y++] = g[i][j];
			}
			x++;
			y = 1;
		}
		if (jud()) return 1;
		else return 0;
	} else if (k == 5) {
		for (int i = 1; i <= n; i++) {
			for (int j = n; j >= 1; j--) {
				ggg[x][y++] = g[i][j];
			}
			x++;
			y = 1;
		}
		x = y = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = n; j >= 1; j--) {
				gggg[x][y++] = ggg[j][i];
			}
			x++;
			y = 1;
		}
		x = y = 1;
		for (int i = n; i >= 1; i--) {
			for (int j = n; j >= 1; j--) {
				ggggg[x][y++] = ggg[i][j];
			}
			x++;
			y = 1;
		}
		x = y = 1;
		for (int i = n; i >= 1; i--) {
			for (int j = n; j >= 1; j--) {
				gggggg[x][y++] = ggg[i][j];
			}
			x++;
			y = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (gg[i][j] != gggg[i][j]) {
					key = 0;
					break;
				}
			}
			if (!key) break;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (gg[i][j] != ggggg[i][j]) {
					flag = 0;
					break;
				}
			}
			if (!flag) break;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (gg[i][j] != gggggg[i][j]) {
					ffl = 0;
					break;
				}
			}
			if (!ffl) break;
		}
		if (key || flag || ffl) return 1;
	} else if (k == 6) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (g[i][j] != gg[i][j]) return 0;
			}
		}
		return 1;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> gg[i][j];
		}
	}
	if (dec(1)) printf("1");
	else if (dec(2)) printf("2");
	else if (dec(3)) printf("3");
	else if (dec(4)) printf("4");
	else if (dec(5)) printf("5");
	else if (dec(6)) printf("6");
	else printf("7");
	return 0;
}
