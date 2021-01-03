#include<stdio.h>
long long int max(long long int a[],int n);
long long int min(long long int a[],int n);
long long int yinshumax(long long int x,long long int y);
int main()
{
	long long int a[3];
	for(int i=0;i<3;i++)
	{
		scanf("%lld",&a[i]);
	}
	long long int b,c,d;
	b=min(a,3);
	c=max(a,3);
	d=yinshumax(b,c);
	printf("%lld/%lld",b/d,c/d);
	return 0;

}
long long int max(long long int a[],int n)
{
	long long int k=a[0];
	for(int i=1;i<n;i++)
	{
		if(k<=a[i])
		k=a[i];
	}
	return k;
}
long long int min(long long int a[],int n)
{
	long long int k=a[0];
	for(int i=1;i<n;i++)
	{
		if(k>=a[i])
		k=a[i];
	}
	return k;
}
long long int yinshumax(long long int x,long long int y)//最大公因数(相减法求公因数)
{
	if(x==0||y==0)
	return x;
	while(x!=y)
	{
		if(x>y) x=x-y;
		if(x<y) y=y-x;
	}
	return x;
}
//P1888 三角函数
//题目网址：https://www.luogu.com.cn/problem/P1888
//由于指针的应用还不熟悉，所以用了很长的代码来解决
//排序提取最大值和最小值，还有进行约分等操作。
//整体而言似乎没有必要用到ll，不过我也不知道int
//会不会爆（滑稽）
//思路简单，操作不难。
