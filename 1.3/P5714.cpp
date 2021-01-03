#include<stdio.h>
int main()
{
	float m,h,bmi;
	scanf("%f%f",&m,&h);
	bmi=m/h/h;
	if(bmi<18.5) printf("Underweight");
	if(bmi>=18.5&&bmi<24) printf("Normal");
	if(bmi>=24) printf("%.4f\nOverweight",bmi);
	return 0;
}
//题目网址：https://www.luogu.com.cn/problem/P5714
//P5714 【深基3.例7】肥胖问题
//看到四舍五入保留六位有效数字输出，一下子迷了
//第一，我用的是C语言，也就是题目所说的非C++语言
//这就很难过了，从来没有学过哪个修饰符是能够保留
//有效数字的(我当时都有点想要学C++)
//不过经过分析后，当bmi>=24时，小数点前基本都是两
//位数，也就是说不必考虑小数点前时几位，直接%.4f就
//行了。最后AC也验证了我的想法
