#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include<unordered_map>

using namespace std;

typedef long long LL;
const int M = 5;
const int N = 10000;
LL sum[N + 1], scnt;
int b[N + 1];

int main()
{
    int n;
    while(~scanf("%d", &n) && n) {
        for(int i = 0; i < n; i++) {
            int cours[M];
            for(int i = 0; i < M; i++)
                scanf("%d", &cours[i]);
            sort(cours, cours + M);
            LL val = 0;
            for(int i = 0; i < M; i++)
                val *= 1000, val += cours[i];
            sum[i] = val;
        }

        sort(sum, sum + n);

        int maxv = 0, cnt = 0, k = 1;
        sum[n] = 0;
        for(int i = 0; i < n; i++)
            if(sum[i] == sum[i + 1]) k++;
            else {
                b[cnt++] = k;
                maxv = max(maxv, k);
                k = 1;
            }

        int ans = 0;
        for(int i = 0; i < cnt; i++)
            if(b[i] == maxv) ans += maxv;

        printf("%d\n", ans);
    }

    return 0;
}
