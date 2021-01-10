#include<bits/stdc++.h>
using namespace std;
int sum = 1;
void pan (int n) {
	if (n == 1) return;
	sum += 1;
	sum *= 2;
	pan(n - 1);
} 
int main() {
	int n;
	scanf("%d", &n);
	pan(n);
	printf("%d", sum);
	return 0;
}
