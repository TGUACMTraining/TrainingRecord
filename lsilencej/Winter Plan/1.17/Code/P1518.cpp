#include<bits/stdc++.h>
using namespace std;
char g[15][15];
int fx, fy, cx, cy, n, m, d[12][12][12][12][4][4];
int main() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'F') {
				fx = i;
				fy = j;
			}
			if (g[i][j] == 'C') {
				cx = i;
				cy = j;
			}
		}
	}
	for (int i = 0; ; i++) {
		if (fx == cx && fy == cy) {
			printf("%d", i);
			return 0;
		}
		if (n == 0 && fx - 1 >= 1 && g[fx - 1][fy] != '*') fx--;
		else if (n == 1 && fy + 1 <= 10 && g[fx][fy + 1] != '*') fy++;
		else if (n == 2 && fx + 1 <= 10 && g[fx + 1][fy] != '*') fx++;
		else if (n == 3 && fy - 1 >= 1 && g[fx][fy - 1] != '*') fy--;
		else n = (n + 1) % 4;
		if (m == 0 && cx - 1 >= 1 && g[cx - 1][cy] != '*') cx--;
		else if (m == 1 && cy + 1 <= 10 && g[cx][cy + 1] != '*') cy++;
		else if (m == 2 && cx + 1 <= 10 && g[cx + 1][cy] != '*') cx++;
		else if (m == 3 && cy - 1 >= 1 && g[cx][cy - 1] != '*') cy--;
		else m = (m + 1) % 4;
		if (d[fx][fy][cx][cy][n][m]) break;
		else d[fx][fy][cx][cy][n][m] = 1;
	}
	printf("0");
	return 0;
}
