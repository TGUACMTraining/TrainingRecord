#include <algorithm>
#include <iostream>
using namespace std;
struct NINE {
    int ori;
    int mod;
    int k;
} arr[(int)1e5 + 10];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i].ori);
            arr[i].mod = arr[i].ori % 9;
            arr[i].k = arr[i].ori / 9;
            if (!arr[i].mod) {
                arr[i].k--;
                arr[i].mod = 9;
            }
        }
        auto cmp = [](NINE i, NINE j) -> bool {
            if (i.mod == j.mod)
                return i.k < j.k;
            return i.mod < j.mod;
        };
        sort(arr, arr + n, cmp);
        int last = 0;
        int t = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].mod != last) {
                last = arr[i].mod;
                t = 0;
            }
            ans += arr[i].k - t++;
        }
        switch (ans & 1) {
        case 1:
            printf("A\n");
            break;

        default:
            printf("B\n");
            break;
        }
    }
}