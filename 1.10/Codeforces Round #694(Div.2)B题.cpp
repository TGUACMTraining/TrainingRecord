#include<stdio.h>
int main()
{
	int t,n,x,a[200];
	scanf("%d",&t);
	while(t--)
	{
		long long int sum=0;
		scanf("%d %d",&n,&x);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(int i=0,j=n;i<j;i++)
		{
			if(a[i]%x) break;
			else
			{
				for(int k=1;k<=x;k++)
				{
					a[j]=a[i]/x;
					j++;
				}
				sum+=a[i];
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
