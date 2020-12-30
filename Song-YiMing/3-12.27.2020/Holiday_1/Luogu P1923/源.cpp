#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

using namespace std;
int n, th, que[5000050];
void swap(int& a, int& b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}
void msort(int front, int tail)
{
	int mid = que[(front + tail) / 2];
	int l = front, r = tail;
	while (l <= r)
	{
		while (que[l] < mid)l++;
		while (que[r] > mid)r--;
		if (l <= r) {
			swap(que[l], que[r]);
			l++;
			r--;
		}
	}
	if (th <= r) {
		msort(front, r);
	}
	else if (th >= l) {
		msort(l, tail);
	}
	else {
		printf("%d", que[th + 1]);
	}


}
int main()
{
	scanf("%d%d", &n, &th);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", que + i);
	}
	msort(1, n);
	return 0;
}