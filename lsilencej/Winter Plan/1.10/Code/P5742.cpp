#include<bits/stdc++.h>
using namespace std;
struct Stu{
	int id;
	int x, y;
	int sum;
	double zong;
} p[5000];
void judge(Stu a) {
	if (a.sum > 140 && a.zong >= 80) printf("Excellent\n");
	else printf("Not excellent\n");
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c	;
		scanf("%d%d%d", &a, &b, &c);
		p[i].id = a;
		p[i].x = b;
		p[i].y = c;
		p[i].sum = b + c; 
		p[i].zong = b * 0.7 + c * 0.3;
	}
	for (int i = 1; i <= n; i++) judge(p[i]);
	return 0;
}
