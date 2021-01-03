#include<stdio.h>
int main()
{
	int a,b,c,temp;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	if(a>c)
	{
		temp=a;
		a=c;
		c=temp;
	}
	if(b>c)
	{
		temp=b;
		b=c;
		c=temp;
	}
	printf("%d %d %d",a,b,c);
	return 0;
}
//题目网址：https://www.luogu.com.cn/problem/P5715
//P5715 【深基3.例8】三位数排序
//该题如果是用C++不过是几行代码的事，用C语言的话如果
//是较多数字的排序的话，就需要编写函数来解决，但是这
//是很经典的三个数比较，所以直接用三段if解决即可，中
//间用变量temp作为中间变量实现两个变量的交换
//当然也有只用两个变量就实现了两个变量的交换，需要用
//算法就是了。具体的话有用加减法的，
//也有异或法的。

//异或法
//#include <stdio.h>
//int main()
//{
//    int a = 3;
//    int b = 5;
//
//    a = a ^ b;
//    b = a ^ b;
//    a = a ^ b;
//
//    printf("%d,%d\n",a,b);
//}
//
////加减法
//#include <stdio.h>
//
//int main()
//{
//   int a = 3;
//   int b = 5;
//
//   a = a + b;
//   b = a - b;
//   a = a - b;
//
//   printf("%d,%d\n",a,b);
//}
