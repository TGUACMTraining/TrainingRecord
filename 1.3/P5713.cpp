#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(n<6) printf("Local");
	else printf("Luogu");
	return 0;
}
//P5713 【深基3.例5】洛谷团队系统
//题目网址：https://www.luogu.com.cn/problem/P5713
//分析易得，当n>=6时，Luogu最好，故分两种情况
