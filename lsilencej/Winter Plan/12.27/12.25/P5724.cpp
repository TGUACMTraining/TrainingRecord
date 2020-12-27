#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int a[500];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	printf("%d", a[n] - a[1]);
	return 0;
}
