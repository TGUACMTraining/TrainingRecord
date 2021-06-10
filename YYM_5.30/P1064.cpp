#include <iostream>
#include <list>
#include <vector>
using namespace std;
bool not_root[70];
vector<int> child[70];
int imp[70];
int cost[70];
int money;
int num;
const int m_limit = 3.2e4 + 10;
struct item {
    int cost, want;
};
list<item> zos[70];
int tail;
int ans[m_limit];
int main()
{
    scanf("%d%d", &money, &num);
    for (int i = 1; i <= num; i++) {
        int cst, ip, fa;
        scanf("%d%d%d", &cst, &ip, &fa);
        if (fa != 0) {
            child[fa].push_back(i);
            not_root[i] = true;
        }
        imp[i] = ip;
        cost[i] = cst;
    }
    for (int i = 1; i <= num; i++) {
        if (!not_root[i]) {
            int zo[m_limit] = { 0 };
            int this_ans[m_limit] = { 0 };
            for (auto c : child[i]) {
                for (int ct = money - cost[i]; ct >= cost[c]; ct--) {
                    zo[ct] = max(zo[ct], zo[ct - cost[c]] + imp[c] * cost[c]);
                }
            }
            for (int ct = money; ct >= cost[i]; ct--) {
                this_ans[ct] = zo[ct - cost[i]] + imp[i] * cost[i];
            }
            zos[++tail].push_back({ 0, 0 });
            for (int i = 0; i <= money; i++) {
                if ((*zos[tail].begin()).want != this_ans[i]) {
                    zos[tail].push_front({ i, this_ans[i] });
                }
            }
        }
    }
    for (int bag_i = 1; bag_i <= tail; bag_i++) {
        auto& bag = zos[bag_i];
        for (int i = money; i >= 0; i--) {
            for (auto itm : bag) {
                if(i-itm.cost>=0)
                ans[i] = max(ans[i], ans[i - itm.cost] + itm.want);
            }
        }
    }
    printf("%d", ans[money]);
}