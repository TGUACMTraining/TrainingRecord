#include <iostream>
#include <list>
#include <map>
using namespace std;
int money_limit;
int items;
struct atm {
    int money;
    int imp;
};
struct Item {
    atm father;
    list<atm> child;
};
map<int, Item> m;
int ans[(int)3.2e4 + 10];
int arr_child[(int)3.2e4 + 10];
int arr_father[(int)3.2e4 + 10];
int cache[(int)3.2e4 + 10];
int main()
{
    scanf("%d%d", &money_limit, &items);
    for (int i = 1; i <= items; i++) {
        int a, b, f;
        scanf("%d%d%d", a, b, f);
        if (f == 0)
            m[i].father = { a, b };
        else
            m[f].child.push_back({ a, b });
    }
    for (auto Index : m) {
        auto& itm = Index.second;
        memset(arr_child, 0, sizeof(arr_child));
        for (auto x : itm.child) {
            register int money = money_limit - itm.father.money;
            for (; money >= x.money; money--) {
                arr_child[money] = max(arr_child[money], arr_child[money - x.money] + x.imp * x.money);
            }
        }
        memset(arr_father,0,sizeof(arr_father));
        for(int i=itm.father.money;i<=money_limit;i++){
            arr_father[i]=itm.father.money+arr_child[i-itm.father.money];
        }

    }
}