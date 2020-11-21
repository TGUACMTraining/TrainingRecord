- ### 原题：(HDOJ 2899)[Strange fuction](http://acm.hdu.edu.cn/showproblem.php?pid=2899)

> # Strange fuction
>
> ***Time Limit: 2000/1000 MS (Java/Others)  Memory Limit: 32768/32768 K (Java/Others)
> Total Submission(s): 14992  Accepted Submission(s): 9941***

## Problem Description

Now, here is a fuction:
 F(x) = 6 * x^7+8*x^6+7*x^3+5*x^2-y*x (0 <= x <=100)
Can you find the minimum value when x is between 0 and 100.





## Input

The first line of the input contains an integer T(1<=T<=100) which means the number of test cases. Then T lines follow, each line has only one real numbers Y.(0 < Y <1e10)





## Output

Just the minimum value (accurate up to 4 decimal places),when x is between 0 and 100.



## Sample Input



> ```
> 2
> 100
> 200
> ```



## Sample Output



> ```
> -74.4291
> -178.8534
> ```



- ### 题意：

> 大致意思就是用输入T个Y的值，分别求出每个Y的值对应的F(x)的最小结果



- ### 解题思路：

> 要求最小值，只要求函数f(x)的导数值等于0即可，寻找导数等于0时的x的值即可，用二分加快寻找速度



- ### 代码：

~~~cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;
int t, y;
double fx(double x) {
	return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * x * x - y * x; // f(x) 
}
double fxx(double x) {
	return 42 * pow(x, 6) + 48 * pow(x, 5) + 21 * pow(x, 2) + 10 * x - y; // f(x)的导数 
}
double fd() { // 找到这样的x 
	double l = 0, r = 100;
	double m = (l + r) / 2;
	while ((r - l) >= 1e-6) { // 实数二分一般精度在后两位 
		m = (l + r) / 2;
		if (fxx(m) == 0) return m; // 只要f(x)的导数等于0，即为最小值 
		else if (fxx(m) < 0) l = m;
		else r = m;
	}
	return m;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &y);
		printf("%.4lf\n", fx(fd()));
	}
	return 0;
}
~~~

这是一道实数二分的模板题，要知道当导数值为0时即为函数的最小值，找到导数为0时的x即可

