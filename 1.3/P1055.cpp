#include<stdio.h>
int main()
{
	char a,b,c,d,e,f,g,h,i,j,l,m,n; int sum;
	scanf("%c-%c%c%c-%c%c%c%c%c-%c",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
	sum=1*(a-'0')+2*(b-'0')+3*(c-'0')+4*(d-'0')+5*(e-'0')+6*(f-'0')+7*(g-'0')+8*(h-'0')+9*(i-'0');
	if((j=='X')&&sum%11==10){
		printf("Right");return 0;
	}
	if(sum%11==(j-'0'))
	printf("Right");
	else
	if(sum%11==10)
	printf("%c-%c%c%c-%c%c%c%c%c-X",a,b,c,d,e,f,g,h,i);
	else
	printf("%c-%c%c%c-%c%c%c%c%c-%d",a,b,c,d,e,f,g,h,i,sum%11);
	return 0;
}
//P1055 [NOIP2008 普及组] ISBN 号码
//题目网址：https://www.luogu.com.cn/problem/P1055
//思路很简单：输入时直接以字符形式输入，然后再进行
//累加，中间减去'0'进行运算，最后再进行验证即可。
