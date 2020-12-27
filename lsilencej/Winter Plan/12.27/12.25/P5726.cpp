#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int a[5000];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	double sum;
	for (int i = 2; i <= n - 1; i++) sum += a[i];
	printf("%.2lf", sum / (n - 2)); 
	return 0;
}
