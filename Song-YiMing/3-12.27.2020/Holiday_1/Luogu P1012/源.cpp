#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
char c[21][10];

int gcd(int a, int b)
{
	if (b == 0)return a;
	else return gcd(b, a % b);
}
bool cmp(char* a, char* b)
{
	int lena = strlen(a),
		lenb = strlen(b);
	for (int i = 0; i < lena * lenb / gcd(lena, lenb); i++)
	{
		if (a[i % lena] < b[i % lenb])return 1;
		else if (a[i % lena] > b[i % lenb])return 0;
	}
	return 0;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", c[i]);
	}
	bool b[22] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		int p = 0;
		int j = 1;
		while (b[j])j++;
		p = j++;
		for (; j <= n; j++)
		{
			if (!b[j] && cmp(c[p], c[j])) {
				p = j;
			}
		}
		b[p] = 1;
		printf("%s", c[p]);
	}
	return 0;
}