#include<stdio.h>
int main()
{
	int n,z1,z2,z3,p1,p2,p3,p[3]={0},z[3]={0};
	//n为所需的铅笔数量，z为该种包装铅笔的支数，p为价格
	scanf("%d",&n);
	scanf("%d %d %d %d %d %d",&z1,&p1,&z2,&p2,&z3,&p3);
	while(z[0]<n){p[0]+=p1;z[0]+=z1;}
	while(z[1]<n){p[1]+=p2;z[1]+=z2;}
	while(z[2]<n){p[2]+=p3;z[2]+=z3;}
	int a=p[0];
	for(int i=1;i<3;i++)
	{
		if(p[i]<a) a=p[i];
	}
	printf("%d",a);
	return 0;
}
//P1909 [NOIP2016 普及组] 买铅笔
//题目网址：https://www.luogu.com.cn/problem/P1909
//按照所需的铅笔数，分别计算每种铅笔最少需要多少钱，
//这个用while循环从0开始算，每次加一，一直算到满足
//条件为止，然后再进行判断从而选出最小值并输出即可。
