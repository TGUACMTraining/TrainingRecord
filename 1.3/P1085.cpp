#include<stdio.h>
int main()
{
	int a,b,count=1,sum=0,day=7;
	scanf("%d %d",&a,&b);
	sum=a+b;
	for(int i=2;i<=7;i++)
	{
		scanf("%d %d",&a,&b);
		if(sum<(a+b))
		{
			sum=a+b;
			count=i;
		}
	}
	printf("%d",count);
	return 0;
}
//P1085 [NOIP2004 普及组] 不高兴的津津
//题目网址：https://www.luogu.com.cn/problem/P1085
//这个题很有趣味。只需用循环嵌套一个判断解决即可。
