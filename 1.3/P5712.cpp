#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	if(a<=1) printf("Today, I ate %d apple.",a);
	else printf("Today, I ate %d apples.",a);
	return 0;
}
//P5712 【深基3.例4】Apples
//题目网址：https://www.luogu.com.cn/problem/P5712
//此题可以分成两个方面，一个是单数，一个是复数。
//如果还要再改进，也就这么写吧
//a<=1?(printf("Today, I ate %d apple.",a)):(printf("Today, I ate %d apples.",a));
