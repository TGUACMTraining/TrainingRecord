- ### 原题：(HDOJ 1556)[Color the ball](http://acm.hdu.edu.cn/showproblem.php?pid=1556)

> # 最大子矩阵
>
> ***Time Limit: 9000/3000 MS (Java/Others)  Memory Limit: 32768/32768 K (Java/Others)
> Total Submission(s): 40940  Accepted Submission(s): 19397***

## Problem Description

N个气球排成一排，从左到右依次编号为1,2,3....N.每次给定2个整数a b(a <= b),lele便为骑上他的“小飞鸽"牌电动车从气球a开始到气球b依次给每个气球涂一次颜色。但是N次以后lele已经忘记了第I个气球已经涂过几次颜色了，你能帮他算出每个气球被涂过几次颜色吗？





## Input

每个测试实例第一行为一个整数N,(N <= 100000).接下来的N行，每行包括2个整数a b(1 <= a <= b <= N)。
当N = 0，输入结束。





## Output

每个测试实例输出一行，包括N个整数，第I个数代表第I个气球总共被涂色的次数。



## Sample Input



> ```
> 3
> 1 1
> 2 2
> 3 3
> 3
> 1 1
> 1 2
> 1 3
> 0
> ```



## Sample Output



> ```
> 1 1 1
> 3 2 1
> ```



- ### 解题思路：

> 直接拿一维数组跑即100000*100000，肯定会超时
>
> 可以使用前缀和的思想，在数组的首位++，在末位后一位--，最后遍历一遍将前面修改过的值都相加即可



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
#include<set>
using namespace std;
int qiu[110000];
int main() {
	int n;
	while (scanf("%d", &n) == 1 && n != 0) {
		memset(qiu, 0, sizeof(qiu));
		int a, b;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &a, &b);
			qiu[a]++;
			qiu[++b]--;
		}
		for (int i = 1; i <= n; i++) {
			qiu[i] += qiu[i - 1];
			if (i == 1) printf("%d", qiu[i]);
			else printf(" %d", qiu[i]);
		}
		printf("\n");
	}
	return 0;
}
~~~

巧妙地使用前缀和思想，不需要树状数组或线段树来进行区间修改，大大减少代码量，能够简单使用一维数组达到o（n）的时间复杂度
