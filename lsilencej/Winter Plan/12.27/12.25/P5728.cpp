#include<bits/stdc++.h>
using namespace std;
struct stu{
	int ch, ma, en, sum;
} a[2000];
int judge(int x, int y) {
	if (abs(a[x].ch - a[y].ch) <=5 && abs(a[x].ma - a[y].ma) <=5 && abs(a[x].en - a[y].en) <=5 && abs(a[x].sum - a[y].sum) <=10) return 1;
	else return 0;
}
int main() {
	int n, t = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i].ch, &a[i].ma, &a[i].en);
		a[i].sum = a[i].ch + a[i].ma + a[i].en; 
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (judge(i, j)) t++;
		}
	}
	printf("%d", t);
}
