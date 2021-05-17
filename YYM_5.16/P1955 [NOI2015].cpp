#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<functional>
using namespace std;
const int limit = 12255871;
int father[limit];
int stk[limit][2];
int tail;
hash<int>h;
inline int ha(int n) {
    return h(n) % limit;
}
int ff(int n) {
    int r = n;
    while (father[r] != r) {
        r = father[r];
    }
    int i = n;
    int j = 0;
    while (i != r) {
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
   /* if (n == father[n]) {
        return n;
    }return father[n] = ff(father[n]);*/
}
void uni(int i, int j) {
    i = ff(i);
    j = ff(j);
    if (i < j) {
        father[i] = j;
    }
    else {
        father[j] = i;
    }
}
void clean() {
    tail = 0;
    for (int i = 0; i < limit; i++) {
        father[i] = i;
    }
}
int main() {
    freopen("P1955_2.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    int i, j, e;
    int n;
    while (t--) {
        cin >> n;
        clean();
        while (n--) {
            cin >> i >> j >> e;
            i = ha(i);
            j = ha(j);
            switch (e)
            {
            case 1:
                uni(i, j);
                break;

            default:
                stk[tail][0] = i;
                stk[tail++][1] = j;
                break;
            }
        }
        int flag = 1;
        while (tail != 0) {
            i = stk[--tail][0];
            j = stk[tail][1];
            if (ff(i) == ff(j)) { flag = 0; break; }
        }
        switch (flag)
        {
        case 1:
            printf("YES\n");
            break;

        default:
            printf("NO\n");
            break;
        }
    }
}