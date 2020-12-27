- ### 原题：(P1303)[A*B Problem](https://www.luogu.com.cn/problem/P1303)

> # P1303 A*B Problem

## 题目描述

求两数的积。

## 输入格式

两行，两个整数。

## 输出格式

一行一个整数表示乘积。

## 输入输出样例

**输入 #1**

```
1 
2
```

**输出 #1**

```
2
```

## 说明/提示

每个数字不超过 10^2000 ，需用高精。



- ### 解题思路：

> 一道高精度乘法的模板题，用两个字符数组分别存两个数的每一位，将每一位对齐，不难发现每一位的规律为c[i + j] += a[i] * b[j]
>
> 所以很容易就出来了答案，最后从后往前枚举，判断新数的位数，再从后往前倒序输出即可



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
int main() {
	char n1[2100], n2[2100];
	int a[2100], b[2100], c[4100];
	int la, lb, lc;
	scanf("%s", n1);
	scanf("%s", n2);
	la = strlen(n1);
	lb = strlen(n2);
	memset(c, 0, sizeof(c));
	for (int i = 0, j = la - 1; i < la; i++, j--) a[i] = n1[j] - '0'; // 从个位开始对齐每一位的数 
	for (int i = 0, j = lb - 1; i < lb; i++, j--) b[i] = n2[j] - '0';
	for (int i = 0; i < la; i++) {
		for (int j = 0; j < lb; j++) {
			c[i + j] += a[i] * b[j]; // 每一位上的规律 
		}
	}
	for (int i = 0; i < la + lb; i++) {
		if (c[i] >= 10) {
			c[i + 1] += c[i] / 10; // 处理进位 
			c[i] %= 10;
		}
	}
	for (lc = la + lb; lc > 0; lc--) if (c[lc] != 0) break; // 判断新数有多少位 
	for (int i = lc; i >= 0; i--) printf("%d", c[i]); // 逆序输出，因为是从个位开始存的 
	return 0;
}
~~~

高精度乘法模板题，最重要的是发现其中的规律，每一位的联系，对齐位时的a，b，c数组要用int类型，否则会出现乱码导致结果不正确

