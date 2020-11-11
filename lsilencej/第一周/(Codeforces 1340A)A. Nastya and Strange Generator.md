- ### 原题：(Codeforces 1340A)[A. Nastya and Strange Generator](https://codeforces.com/contest/1340/problem/A)

> # A. Nastya and Strange Generator
>
> time limit per test：1 second
>
> memory limit per test：256 megabytes
>
> input：standard input
>
> output：standard output



Denis was very sad after Nastya rejected him. So he decided to walk through the gateways to have some fun. And luck smiled at him! When he entered the first courtyard, he met a strange man who was selling something.

Denis bought a mysterious item and it was… Random permutation generator! Denis could not believed his luck.

When he arrived home, he began to study how his generator works and learned the algorithm. The process of generating a permutation consists of 𝑛 steps. At the 𝑖-th step, a place is chosen for the number 𝑖 (1≤𝑖≤𝑛). The position for the number 𝑖 is defined as follows:

- For all 𝑗 from 1 to 𝑛, we calculate 𝑟𝑗 — the minimum index such that 𝑗≤𝑟𝑗≤𝑛, and the position 𝑟𝑗 is not yet occupied in the permutation. If there are no such positions, then we assume that the value of 𝑟𝑗 is not defined.
- For all 𝑡 from 1 to 𝑛, we calculate 𝑐𝑜𝑢𝑛𝑡𝑡 — the number of positions 1≤𝑗≤𝑛 such that 𝑟𝑗 is defined and 𝑟𝑗=𝑡.
- Consider the positions that are still not occupied by permutation and among those we consider the positions for which the value in the 𝑐𝑜𝑢𝑛𝑡 array is maximum.
- The generator selects one of these positions for the number 𝑖. The generator can choose any position.

Let’s have a look at the operation of the algorithm in the following example:

![img](https://espresso.codeforces.com/15abb96c35071a49b2b1acdf0082b04b54f18bd6.png)

Let 𝑛=5 and the algorithm has already arranged the numbers 1,2,3 in the permutation. Consider how the generator will choose a position for the number 4:

- The values of 𝑟 will be 𝑟=[3,3,3,4,×], where × means an indefinite value.
- Then the 𝑐𝑜𝑢𝑛𝑡 values will be 𝑐𝑜𝑢𝑛𝑡=[0,0,3,1,0].
- There are only two unoccupied positions in the permutation: 3 and 4. The value in the 𝑐𝑜𝑢𝑛𝑡 array for position 3 is 3, for position 4 it is 1.
- The maximum value is reached only for position 3, so the algorithm will uniquely select this position for number 4.

Satisfied with his purchase, Denis went home. For several days without a break, he generated permutations. He believes that he can come up with random permutations no worse than a generator. After that, he wrote out the first permutation that came to mind 𝑝1,𝑝2,…,𝑝𝑛 and decided to find out if it could be obtained as a result of the generator.

Unfortunately, this task was too difficult for him, and he asked you for help. It is necessary to define whether the written permutation could be obtained using the described algorithm if the generator always selects the position Denis needs.

**Input**

> The first line contains a single integer 𝑡 (1≤𝑡≤105) — the number of test cases. Then the descriptions of the test cases follow.
>
> The first line of the test case contains a single integer 𝑛 (1≤𝑛≤105) — the size of the permutation.
>
> The second line of the test case contains 𝑛 different integers 𝑝1,𝑝2,…,𝑝𝑛 (1≤𝑝𝑖≤𝑛) — the permutation written by Denis.
>
> It is guaranteed that the sum of 𝑛 over all test cases doesn’t exceed 105.



**Output**

> Print “Yes” if this permutation could be obtained as a result of the generator. Otherwise, print “No”.
>
> All letters can be displayed in any case.



**Example**

**input**

```
5
5
2 3 4 5 1
1
1
3
1 3 2
4
4 2 3 1
5
1 5 2 4 3
```



**output**

```
Yes
Yes
No
Yes
No
```

**Note**

Let’s simulate the operation of the generator in the first test.

At the 1 step, 𝑟=[1,2,3,4,5],𝑐𝑜𝑢𝑛𝑡=[1,1,1,1,1]. The maximum value is reached in any free position, so the generator can choose a random position from 1 to 5. In our example, it chose 5.

At the 2 step, 𝑟=[1,2,3,4,×],𝑐𝑜𝑢𝑛𝑡=[1,1,1,1,0]. The maximum value is reached in positions from 1 to 4, so the generator can choose a random position among them. In our example, it chose 1.

At the 3 step, 𝑟=[2,2,3,4,×],𝑐𝑜𝑢𝑛𝑡=[0,2,1,1,0]. The maximum value is 2 and is reached only at the 2 position, so the generator will choose this position.

At the 4 step, 𝑟=[3,3,3,4,×],𝑐𝑜𝑢𝑛𝑡=[0,0,3,1,0]. The maximum value is 3 and is reached only at the 3 position, so the generator will choose this position.

At the 5 step, 𝑟=[4,4,4,4,×],𝑐𝑜𝑢𝑛𝑡=[0,0,0,4,0]. The maximum value is 4 and is reached only at the 4 position, so the generator will choose this position.

In total, we got a permutation of 2,3,4,5,1, that is, a generator could generate it.



- ### 题意：

> ~~理解题意理解了一年~~
>
> 大概说的是一个叫Denis的人买了个随机数列生成器，然后他想研究生成数列的规则，给你几组~~（十万组）~~排列问你符不符合生成排列的规则，符合就输出"Yes"，不符合则输出"No"
>
> 排列生成的规则：
>
> - 输入一个n，对1~n进行排列操作
>
> - 在第i次操作i的位置
> - r[j]代表j~n区间中的第一个空位（最小），若找不到这样的空位，则r[j]未定义
> - count[j]代表r数组中j出现的次数，每次排列都要检查一遍count数组，取count数组中最大值的位置作为i的位置

- ### 解题思路：

> 之前本来想通过纯模拟来进行实现，发现有点复杂很难实现~~（可能我太菜了）~~，通过样例在草稿纸上进行了模拟，发现了其中的规律：若后一个为空位（即未插入数字），则下一个数字一定插在该空位，即后一个比前一个大1；若从后面开始插起，即后面没有空位的情况，则可以往前面插入所以arr数组只可能有两种情况：
>
> - arr[i] + 1 == arr[i + 1]（严格单增，除非后面没有空位）
> - arr[i] > arr[k]（这种情况即先在后面插了小数，再往前面插大数，中间会产生一个分段点，k为分段点两边严格递增数列的首项）
>
> 所以直接就可以通过这两个条件进行模拟了，用一个arr数组即可，每次存一下开头的值，判断后面是否为严格单增，若不是则判断第二种情况，若两种情况都不符合，则不存在这样的排列

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
	int t, n, minm, maxm, a;
	bool key = true;
	int arr[200000];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n == 1) {
			scanf("%d", &a);
			printf("Yes\n");
			continue;
		}
		memset(arr, 0, sizeof(arr));
		key = true;
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		minm = arr[1];
		maxm = arr[1];
		for (int i = 2; i <= n; i++) {
			if (maxm + 1 == arr[i]) maxm = arr[i]; // maxm存取前一个arr数组里的值，方便与后一个进行比较 
			else if (minm > arr[i]) { // 第二种判断情况 
				minm = arr[i]; // minm记录每个严格单调递增的数列的首项 
				maxm = arr[i]; // 更新maxm的值 
			} else {
				printf("No\n");
				key = false; //标记若输出了"No"则不输出"Yes" 
				break;
			}
		}
		if (key) printf("Yes\n");
	}
	return 0;
}
~~~

用各种翻译软件来机翻，越翻越离谱，查阅各种博客以及一行行慢慢读题才最终理解题目意思，题目不是很难主要是没理解题意，而且cf的数据就离谱，100000组数据每组都是1直接被卡时间，被迫特判1的情况

其实只要多写几个数据找到规律就好了