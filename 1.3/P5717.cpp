#include<stdio.h>
int main()
{
	int a,b,c,temp;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b){temp=a;a=b;b=temp;}
	if(a>c){temp=a;a=c;c=temp;}
	if(b>c){temp=b;b=c;c=temp;}
	if(a+b<=c)
	{
		printf("Not triangle\n");return 0;
	}
		if(a*a+b*b==c*c)
		printf("Right triangle\n");
		else if(a*a+b*b>c*c)
		printf("Acute triangle\n");
		else if(a*a+b*b<c*c)
		printf("Obtuse triangle\n");
		if(a==b||b==c||a==c)
		printf("Isosceles triangle\n");
		if(a==b&&b==c)
		printf("Equilateral triangle\n");
	return 0;
}
//P5717 【深基3.习8】三角形分类
//https://www.luogu.com.cn/problem/P5717
//这题没什么好说的，不过呢，我TM特别想吐槽的
//是竟然输出顺序还有规定但题目却没有说？！
