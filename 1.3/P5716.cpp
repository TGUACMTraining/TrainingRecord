#include<stdio.h>
int main()
{
	int y,m;
	int a1[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	int a2[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d %d",&y,&m);
	if(y%4==0&&y%100!=0||y%400==0)
	printf("%d",a1[m]);
	else
	printf("%d",a2[m]);
	return 0;
}
//P5716 【深基3.例9】月份天数
//题目网址：https://www.luogu.com.cn/problem/P5716
//这相当于判断闰年与月份的结合，只需要用数组解决即可。
