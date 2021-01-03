#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	if(a%2==0&&4<a&&a<=12)
	  printf("1 1 0 0\n");
	else
	  if(a%2==0||4<a&&a<=12)
	    printf("0 1 1 0\n");
	  else
	    printf("0 0 0 1\n");
	return 0;
}
//网址：https://www.luogu.com.cn/problem/P5710
//P5710 【深基3.例2】数的性质
//经过分析可知，所有情况的真值可总结为一下三种
//1100，0110，0001，故只需要对其进行分类讨论即可
//比较有意思的就是命题的否定所包含的情况，如果
//能够理清，代码都能写得比较简洁。整体而言，这是
//一道很简单的题
