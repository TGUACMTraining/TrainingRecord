#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n, m, a;
	long long x, y;
	scanf("%lld%lld%lld", &n, &m, &a);
	if (m % a) x = m / a + 1;
	else x = m / a;
	if (n % a) y = n / a + 1;
	else y = n / a;
	printf("%lld", x * y);
	return 0;
}
