- ### 原题：(HDOJ 1027)[Ignatius and the Princess II](http://acm.hdu.edu.cn/showproblem.php?pid=1027)

> # Ignatius and the Princess II
>
> *Time Limit: 2000/1000 MS (Java/Others)  Memory Limit: 65536/32768 K (Java/Others)*
> *Total Submission(s): 16089  Accepted Submission(s): 9235*
> 
>

## Problem Description

Now our hero finds the door to the BEelzebub feng5166. He opens the door and finds feng5166 is about to kill our pretty Princess. But now the BEelzebub has to beat our hero first. feng5166 says, "I have three question for you, if you can work them out, I will release the Princess, or you will be my dinner, too." Ignatius says confidently, "OK, at last, I will save the Princess."

"Now I will show you the first problem." feng5166 says, "Given a sequence of number 1 to N, we define that 1,2,3...N-1,N is the smallest sequence among all the sequence which can be composed with number 1 to N(each number can be and should be use only once in this problem). So it's easy to see the second smallest sequence is 1,2,3...N,N-1. Now I will give you two numbers, N and M. You should tell me the Mth smallest sequence which is composed with number 1 to N. It's easy, isn't is? Hahahahaha......"
Can you help Ignatius to solve this problem?





## Input

The input contains several test cases. Each test case consists of two numbers, N and M(1<=N<=1000, 1<=M<=10000). You may assume that there is always a sequence satisfied the BEelzebub's demand. The input is terminated by the end of file.





## Output

For each test case, you only have to output the sequence satisfied the BEelzebub's demand. When output a sequence, you should print a space between two numbers, but do not output any spaces after the last number.



## Sample Input



> ```
> 6 4
> 11 8
> ```



## Sample Output



> ```
> 1 2 3 5 6 4
> 1 2 3 4 5 6 7 9 8 11 10
> ```



- ### 题意：

> 多组数据，给一个数n，从1~n进行从小到大排列，输出第m小的排列



- ### 解题思路：

> 通过c++ algorithm库中的全排列next_permutation函数可以很快实现，next_permutation函数即从小到大输出排列组合，加一个计数器t用来计数，当t与m相等时输出该排列即可



- ### 代码：

~~~cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
int main() {
	int n, m, t = 1;
	int s[1500];
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(s, 0, sizeof(s)); // 每次循环清空数组 
		t = 1;
		for (int i = 0; i < n; i++) s[i] = i + 1;
		while (next_permutation(s, s + n)) { // 全排列 
			t++; // 计数器，和m进行比较选取第m个 
			if (t == m) {
				for (int i = 0; i < n - 1; i++) printf("%d ", s[i]);
				printf("%d\n", s[n - 1]);
				break;
			}
		}
	}
	return 0;
}
~~~

这是一道对next_permutation函数的运用，当然也可以自己用循环写出一个全排列函数进行从小到大排列

之前忘记全排列函数这一说，一直陷入找规律的死循环中，疯狂用排列组合来进行模拟，模拟半天感觉太难实现了~~（还是我菜）~~

