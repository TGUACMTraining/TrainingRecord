#include<stdio.h>
int main()
{
	long long int x,n,w=0,d=0,n1,n2,n3;
	scanf("%lld%lld",&x,&n);
	if(n-1<=7-x)//经过n天后仍然在一周内；
	{
		if(x+(n-1)==6)
		d=n-1;
		if(x+(n-1)==7)
		d=n-2;
	}
	else
	{
 		if(7-x+1>2)
 		d+=7-x+1-2;
		n1=(n-1)-(7-x);
		n2=n1/7;
		w+=n2;
		n3=n1%7;
		if(n3==6)
		d+=(n3-1);
		else if(n3==7)
		d+=(n3-2);
		else d+=n3;
	}
	printf("%lld",(d+w*5)*250);
	return 0;
}
//P1424 小鱼的航程(改进版)
//题目网址：https://www.luogu.com.cn/problem/P1424
//这升级升级得很有挑战性。解题思路如下：
//意识到周末休息，所以分两种情况，一种是经过n天仍然
//在第一周内，另外一种是经过n天后在第N周，这个计算
//方式有所不同，故分类计算。
//但是在计算第二种情况时，没有意识到开始时如果在周末
//的情况，以至于第一次提交出现WA，后来则添加了个if语句
//在else后面，终于AC了。有趣，实在有趣。
