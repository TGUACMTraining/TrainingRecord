#include<bits/stdc++.h>
using namespace std;
double p[500];
int main() {
	int n, m, t = 1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int mmin = 99999, mmax = -99999;
		double sum = 0;
		for (int j = 1; j <= m; j++) {
			int gra;
			scanf("%d", &gra);
			if (gra < mmin) mmin = gra;
			if (gra > mmax) mmax = gra;
			sum += gra; 
		}
		sum = sum - mmin - mmax;
		p[t++] = sum / (m - 2);
	}
	sort(p + 1, p + 1 + n);
	printf("%.2lf", p[n]);
	return 0;
}
