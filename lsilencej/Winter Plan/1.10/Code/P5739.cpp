#include<bits/stdc++.h>
using namespace std;
int jie(int n) {
	if (n == 0 || n == 1) return 1;
	else return n * jie(n - 1);
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", jie(n));
	return 0;
}
