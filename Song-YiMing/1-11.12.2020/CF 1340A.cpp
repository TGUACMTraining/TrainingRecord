#include<cstdio>
#include<string.h>
using namespace std;
int n,m,arr[100010];
inline void dwork()
{
	int temp=arr[1];
	for (int i = 2; i <= m; i++)
	{
		if (arr[i] - arr[i - 1] != 1) {
			if (arr[i] > temp) {
				printf("No\n");
				return;
			}
			else temp = arr[i];
		}
	}
	printf("Yes\n");
	return;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", arr + j);
		}
		dwork();
	}
	return 0;
}
