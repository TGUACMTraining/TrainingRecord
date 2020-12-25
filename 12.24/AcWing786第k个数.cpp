#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, k;
const int N = 1e6 + 10;

int a[N];

void quick_sort(int a[], int l, int r)
{
    if(l >= r)  return;

    int x = a[l + r >> 1], i = l - 1, j = r + 1;
    while(i < j)
    {
        do i ++; while(a[i] < x);
        do j --; while(a[j] > x);
        if(i < j)   swap(a[i], a[j]);
    }

    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}

int main()
{
    scanf("%d%d", &n, &k);

    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);

    quick_sort(a, 0, n - 1);

    printf("%d", a[k - 1]);
	
	return 0; 
}

