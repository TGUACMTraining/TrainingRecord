#include <bits/stdc++.h>
using namespace std;
const int q = 100010;
int o_index = 0;
int greater_index = 0;
int less_index = 0;
int height[q] = {0};
int greater_height[q] = {0};
int less_height[q] = {0};
int main()
{
    int c;
    while (~scanf("%d", &c))
    {
        height[o_index++] = c;
    }
    greater_height[0] = less_height[0] = height[0];
    for (int i = 1; i < o_index; i++)
    {
        if (height[i] <= less_height[less_index])
            less_height[++less_index] = height[i];
        else
            *(upper_bound(less_height, less_height + less_index, height[i], greater<int>())) = height[i];
        if (height[i] > greater_height[greater_index])
            greater_height[++greater_index] = height[i];
        else
            *(lower_bound(greater_height, greater_height + greater_index, height[i])) = height[i];
    }
    cout<<less_index+1<<" "<<greater_index+1<<endl;

    return 0;
}