#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
#define MAXN 100000
#define MAXL 1000000
int prime[MAXN];
bool check[MAXL];
 
int main(void)
{
    // freopen("prime.txt","w",stdout);
    int n, count;
    while (~scanf("%d", &n))
    {
        memset(check, 0, sizeof(check));
        count = 0;
        for (int i = 2; i <= n; i++)
        {
            if (!check[i])	//如果是素数 
                prime[count++] = i;	//记录在数组中 
            for (int j = 0; j < count; j++)	
            {
                if (i*prime[j] > MAXL)	//判断是否越界 
                    break; // 过大的时候跳出
                check[i*prime[j]] = 1; //如果check[i*prime[j]]是已知素数的整数倍那一定是合数
                if ( (i%prime[j]) == 0 ) // 如果i是一个合数，而且i % prime[j] == 0
                    break; 
            }
        }
        for (int i = 0; i < count; i++)
            printf("%d\n", prime[i]);
        for (int i = 0; i < n+1; i++)
           cout<<check[i]<<"\t"; 
    }
    return 0;
}
 