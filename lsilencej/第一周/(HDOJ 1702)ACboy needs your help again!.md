- ### 原题：(HDOJ 1702)[ACboy needs your help again!](http://acm.hdu.edu.cn/showproblem.php?pid=1702)

> # ACboy needs your help again!
>
> *Time Limit: 1000/1000 MS (Java/Others)  Memory Limit: 32768/32768 K (Java/Others)*
> *Total Submission(s): 18852  Accepted Submission(s): 9325*

## Problem Description

ACboy was kidnapped!!
he miss his mother very much and is very scare now.You can't image how dark the room he was put into is, so poor :(.
As a smart ACMer, you want to get ACboy out of the monster's labyrinth.But when you arrive at the gate of the maze, the monste say :" I have heard that you are very clever, but if can't solve my problems, you will die with ACboy."
The problems of the monster is shown on the wall:
Each problem's first line is a integer N(the number of commands), and a word "FIFO" or "FILO".(you are very happy because you know "FIFO" stands for "First In First Out", and "FILO" means "First In Last Out").
and the following N lines, each line is "IN M" or "OUT", (M represent a integer).
and the answer of a problem is a passowrd of a door, so if you want to rescue ACboy, answer the problem carefully!





## Input

The input contains multiple test cases.
The first line has one integer,represent the number oftest cases.
And the input of each subproblem are described above.





## Output

For each command "OUT", you should output a integer depend on the word is "FIFO" or "FILO", or a word "None" if you don't have any integer.



## Sample Input



> ```
>4
> 4 FIFO
> IN 1
>IN 2
> OUT
>OUT
> 4 FILO
> IN 1
> IN 2
> OUT
> OUT
> 5 FIFO
> IN 1
>IN 2
>  OUT
>OUT
> OUT
>5 FILO
> IN 1
>IN 2
> OUT
> IN 3
> OUT
>```
>  



## Sample Output



> ```
>1
> 2
> 2
>1
> 1
>2
> None
> 2
> 3
> ```



- ### 题意：

> 大致意思就是用栈和队列来实现题目中的不同输入输出顺序，"FIFO"代表先进先出，"FILO"代表先进后出，栈或队列为空时输出"None"



- ### 解题思路：

> 利用c++中的栈和队列数据结构进行操作，"FIFO"用队列来模拟，"FILO"用栈来模拟



- ### 代码：

~~~cpp
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
using namespace std;
int main() {
    int t, cmd, num, qnum, snum;
    string fio, io;
    queue<int> q;
    stack<int> s;
    scanf("%d", &t);
    while (t--) {
        while (!q.empty()) q.pop();
        while (!s.empty()) s.pop();
        scanf("%d", &cmd);
        getchar();
        cin >> fio;
        if (fio == "FIFO") { // 用队列模拟先进先出 
            while (cmd--) {
                getchar();
                cin >> io;
                if (io == "IN") {
                    scanf("%d", &num);
                    q.push(num);
                }
                if (io == "OUT") {
                    if (q.empty()) { //  检查队列是否为空 
                        printf("None");
                        continue;
                    }
                    qnum = q.front();
                    printf("%d\n", qnum);
                    q.pop();
                }
            }
        } else { // 用栈模拟先进后出 
            while (cmd--) {
                getchar();
                cin >> io;
                if (io == "IN") {
                    scanf("%d", &num);
                    s.push(num);
                }
                if (io == "OUT") {
                    if (s.empty()) { // 检查栈是否为空 
                        printf("None\n");
                        continue;
                    }
                    snum = s.top();
                    printf("%d\n", snum);
                    s.pop();
                }
            }
        }
    }
    return 0;
}
~~~

这是一道栈和队列的简单应用题，注意好输入输出的处理即可

