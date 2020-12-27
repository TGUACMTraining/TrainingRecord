#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
int main() {
	long long n, t;
	scanf("%lld%lld", &n, &t);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	nth_element(a + 1, a + t + 1, a + n + 1); // STL库函数，时间复杂度为O(n) ，只排序第t小的数，t前面一定比它小，后面一定比它大，但顺序不确定 
	printf("%lld", a[t + 1]);
	return 0;
}
