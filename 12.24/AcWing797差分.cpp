#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
const int N = 1e5 + 10;
int a[N], b[N];

int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i] - a[i - 1];
	}
	
	while (m --)
	{
		int l, r, c;
		scanf("%d %d %d", &l, &r, &c);
		b[l] += c;
		b[r + 1] -= c;
	}
	
	for (int i = 1; i <= n; i ++)
	{
		b[i] = b[i - 1] + b[i];
		printf("%d ", b[i]);
	}
	return 0;
}
