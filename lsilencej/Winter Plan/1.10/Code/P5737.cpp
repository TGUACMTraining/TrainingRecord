#include<bits/stdc++.h>
using namespace std;
int y[5000];
int judge(int ye) {
	if (ye % 4 == 0) {
		if (ye % 100 != 0) return 1;
		else if(ye % 400 == 0) return 1;
	}
	return 0;
}
int main() {
	for (int i = 1582; i <= 3000; i++) if (judge(i)) y[i] = 1;
	int a, b;
	int t = 0;
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; i++) if (y[i]) t++;
	printf("%d\n", t);
	for (int i = a; i <= b; i++) if (y[i]) printf("%d ", i);
	return 0;
}
