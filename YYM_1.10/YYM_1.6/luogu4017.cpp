#include <bits/stdc++.h>
const int MAX = 5050;
const int MOD = 80112002;
using namespace std;
int food_chans[MAX] = {0};
// struct stack{
//     int arr[MAX]={0};
//     int head=0;
//     void push(int i){
//         arr[head++]=i;
//     }
//     int top(void ){
//         return arr[head-1];
//     }
//     int empty(void){
//         return !head;
//     }
//     void pop(void){
//         head--;
//     }
// };
stack<int> eat[MAX];
int solve_food_chain(int a)
{
    if (food_chans[a])
    {
        return food_chans[a];
    }
    while (!eat[a].empty())
    {
        food_chans[a] += solve_food_chain(eat[a].top());
        food_chans[a] %= MOD;
        eat[a].pop();
    }
    return food_chans[a];
}
int main()
{
    int n, m;
    cin >> n >> m;
    int can_eat[MAX] = {0};
    int can_be_eat[MAX] = {0};
    int index;
    {
        int a, b;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            eat[b].push(a);
            can_eat[b] = 1;
            can_be_eat[a] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        food_chans[i] = !can_eat[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        solve_food_chain(i);
        if (!can_be_eat[i])
        {
            ans += food_chans[i];
            ans %= MOD;
        }
    }
    cout << ans;

    return 0;
}