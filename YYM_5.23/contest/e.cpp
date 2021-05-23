#include <cstdio>
#include <iostream>
using namespace std;
char fun[(int)1e6 + 10];
long long fxs(int i)
{
    if (fun[i] == '+')
        return fxs(i + 1);
    if (fun[i] == '-')
        return -fxs(i + 1);
    if (fun[i] == 'x')
        return 1;
    long long ans = 0;
    while (isdigit(fun[i]))
    {
        ans *= 10;
        ans += fun[i] & 15;
        i++;
    }
    return ans;
}
long long fcs(int i)
{
    if (fun[i] != '^')
        return 1;
    if (fun[i] == '^')
        i++;
    long long ans = 0;
    while (isdigit(fun[i]))
    {
        ans *= 10;
        ans += fun[i] & 15;
        i++;
    }
    return ans;
}
int main()
{
    scanf("f(x)=%s", fun);
    printf("f'(x)=");
    int i = 0;
    long long xs = 0;
    long long cs = 0;
    int flag = 0;
    for (; fun[i]; i++)
    {
        if (xs == 0)
            xs = fxs(i);
        if (fun[i] == 'x')
        {
            cs = fcs(i+1);
            long long ans = cs * xs;
            if (flag) //+-
            {
                if (ans == 1&&cs == 1)
                {
                    printf("+%lld",ans);
                }
                else if (ans == -1&&cs == 1)
                {
                    printf("%lld",ans);
                }
                else if(ans == 1)
                {
                    printf("+");
                }
                else if(ans == -1)
                {
                    printf("-");
                }
                else
                {
                    //??????
                    printf("%+lld", ans);
                }
            }
            else
            {
                if (ans == 1&&cs == 1)
                {
                    printf("%lld",ans);
                }
                else if (ans == -1&&cs == 1)
                {
                    printf("%lld",ans);
                }
                else if(ans == -1) printf("-");
                else
                {
                    //??????
                    printf("%lld", ans);
                }
                flag = 1;
            }
            if (cs - 1 > 1)
            {
                printf("x^%lld", cs - 1);
            }
            else if (cs - 1 == 1)
            {
//f'(x)=4x^3-6x-1
                printf("x");
            }
            cs = 0;
            xs = 0;
            while ((fun[i] != '+' && fun[i] != '-') && fun[i])
                i++;
            i--;
        }
    }
    if (flag == 0)
    {
        printf("0");
    }
}