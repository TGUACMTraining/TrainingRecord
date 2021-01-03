#include<stdio.h>
#define H 30
int main()
{
	int a[10];
	for(int i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	int h;//陶陶的高度
	scanf("%d",&h);
	int count;
	for(int i=0;i<10;i++)
	{
		if(a[i]<=h+H)
		count++;
	}
	printf("%d",count);
}
//P1046 [NOIP2005 普及组] 陶陶摘苹果
//题目网址：https://www.luogu.com.cn/problem/P1046
//说实话我没想到这么简单的题竟然会出现在题单接近末
//尾的地方。用一个for循环录入苹果高度，记录陶陶身高
//再用计数器在for循环种统计所有站在椅子上所能够到的
//最大高度的苹果个数。思路简单、明了。
