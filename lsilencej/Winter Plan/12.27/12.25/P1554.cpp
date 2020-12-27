#include<bits/stdc++.h>
using namespace std;
int a[10];
int apart(int x) {
	while (x) {
		a[x % 10]++;
		x /= 10; 
	}
	return 0;
}
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = m; i <= n; i++) apart(i);
	for (int i = 0; i <= 9; i++) printf("%d ", a[i]);
	return 0;
}
