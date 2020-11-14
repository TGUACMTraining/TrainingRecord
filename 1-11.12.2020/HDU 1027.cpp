#include<cstdio>

using namespace std;

int main()
{
	int n,m;
	int arr[9]={1,0},brr[10]={0};
	for(int i=1;i<=8;i++)
	{
		arr[i]=arr[i-1]*i;
	}
	while(2==scanf("%d%d",&n,&m))
	{
		int p=1;							//位数 
		while((m-1)/arr[p])p++;
		for(int i=1;i<=n-p;i++)
		{
			printf("%d ",i);
		}
		for(int i=n-p+1;i<=n;i++)
		{
			brr[i-n+p]=i; 
		}
		while(p>1)
		{
			int tp=(m+arr[p-1]-1)/arr[p-1];	//第k小数 
			printf("%d ",brr[tp]);
			for(int i=tp;brr[i];i++)
			{
				brr[i]=brr[i+1];
			}
			m=(m-1)%arr[p-1]+1;
			p--;
		}
		printf("%d",brr[1]);
		printf("\n");
	}
	return 0;
}
//每一位最大值所对应的m值因数 ,最多第八位 
//细节太多了 




