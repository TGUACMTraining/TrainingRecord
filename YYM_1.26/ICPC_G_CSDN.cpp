#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
struct node
{
    int flag; //1表示开机；-1表示关机
    long long time;
} q[200010];
bool cmp(node x, node y) //时间从小到大，相同时间，结束在前，开始在后
{
    if (x.time == y.time)
        return x.flag < y.flag;
    return x.time < y.time;
}
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        long long times = 0; //总时间
        int tip = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld", &q[tip].time, &q[tip + 1].time);
            q[tip].flag = 1;
            q[tip + 1].flag = -1;
            times += q[tip + 1].time - q[tip].time; //先算各个任务工作总时间
            tip += 2;
        }
        sort(q + 1, q + tip, cmp); //注意+tip不是+tip+1
        long long num = 0;         //所用机器数
        stack<long long> s;
        for (int i = 1; i < tip; i++)
        {
            if (q[i].flag == 1)
            {
                if (!s.empty()) //前面有结束时间，即有使用过的机器空闲下来
                {
                    times += q[i].time - s.top(); //加上间隔时间
                    s.pop();
                }
                else
                    num++; //前面机器都在使用中，使用机械数+1
            }
            else
                s.push(q[i].time);
        }
        printf("%lld %lld\n", num, times);
    }
}