#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, q, k;

const int N = 1e6 + 10;

int a[N];

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i ++)	scanf("%d", &a[i]);
	
	while(q--)
	{
		int x;
		scanf("%d", &x);
		
		int l = 0, r = n - 1;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (a[mid] >= x)	r = mid;
			else	l = mid + 1;
		}
		if (a[l] != x)	printf("-1 -1\n");
		else
		{
			printf("%d ", l);
			r = n - 1;
			while (l < r)
			{
				int mid = l + r + 1 >> 1;
				if (a[mid] <= x)	l = mid;
				else	r = mid - 1;
			}
			printf("%d\n", r);
		}
	}
	return 0;
}
