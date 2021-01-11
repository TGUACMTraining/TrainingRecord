#include<stdio.h>
int main()
{
	int K,sumG=0,sumD=0;
	scanf("%d",&K);
	for(int i=1;i;i++)
	{
		if(K)
		for(int j=1;j<=i;j++)
		{
			sumD++;
			sumG+=i;
			if(sumD==K) break;
		}
		else break;
		if(sumD==K) break;
	}
	printf("%d",sumG);
	return 0;
}
//P2669 [NOIP2015 普及组] 金币
//题目网址：https://www.luogu.com.cn/problem/P2669
//解题思路：用一层for循环控制金币，另一层for则用两
//个计数器分别记录金币数目还有天数,当天数==K时跳出
//内层循环，外层循环以同样的条件判断即可。
