#include<stdio.h>
int main()
{
	int y;
	scanf("%d",&y);
	if(y%4==0&&y%100!=0||y%400==0)
	printf("1");
	else
	printf("0");
	return 0;
}
//题目网址：https://www.luogu.com.cn/problem/P5711
//P5711 【深基3.例3】闰年判断
//题目着实简单，这个条件已经是闭着眼都能写出来
