#include<cstdio>

using namespace std;
int m,temp[1001];
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int ewe;
		scanf("%d",&ewe);
		temp[ewe]++;
	}
	for(int i=1;i<=1000;i++)
	{
		if(temp[i])printf("%d ",i);
	}
	return 0;
}
