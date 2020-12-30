#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

using namespace std;
int n, m;
int mmp[1010][1010];//差分与前缀和
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x_1, y_1, x_2, y_2;
		scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
		mmp[x_1][y_1]++;
		mmp[x_1][y_2 + 1]--;
		mmp[x_2 + 1][y_1]--;
		mmp[x_2 + 1][y_2 + 1]++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			mmp[i][j] += mmp[i - 1][j] + mmp[i][j - 1] - mmp[i - 1][j - 1];
			printf("%d ", mmp[i][j]);
		}
		printf("\n");
	}
	return 0;
}