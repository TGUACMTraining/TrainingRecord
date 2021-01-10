#include<bits/stdc++.h>
using namespace std;
int main() {
	long long a, sum = 0, n = 0;
	while (scanf("%lld", &a) != EOF) {
		n++;
		sum += a;
	}
	printf("%lld", sum * (long long)pow(2, n - 1));
	return 0;
}
