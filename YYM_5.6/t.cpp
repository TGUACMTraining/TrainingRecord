#include <iostream>
#include<cstdio>
using namespace std;
const int limit = 5e5 + 10;
struct {
    int stk[limit];
    int tail;
    inline int top()
    {
        return stk[tail - 1];
    }
    void pop()
    {
        tail--;
    }
    void push(int n)
    {
        stk[tail++] = n;
    }
} stk;
bool arr[limit];
int dp[limit];
int from[limit];
int tail;
void f()
{
    for (int i = 1; i <= tail; i++) {
        if (arr[i]) {
            from[i]=from[i-1];
            dp[i]=dp[i-1];
            stk.push(i);
        } else {
            if (stk.tail) {
                if(stk.top()==i-1){
                    from[i]=from[i-1];
                    dp[i]=dp[i-1]+1;
                }else if(stk.top()==from[i-1]-1){
                    from[i]=stk.top();
                    dp[i]=dp[i-1]+1;
                }else{
                    dp[i]=dp[i-1];
                }
                stk.pop();
            }else{
                dp[i]=dp[i-1];
            }
        }
    }
}
int main()
{
    char s[1024];
    cin>>s+1;
    tail=strlen(s+1);
    for(int i=1;i<=tail;i++){

        switch (s[i])
        {
        case '(':
            arr[i]=true;
            break;
        
        default:
            arr[i]=false;
            break;
        }
    }
    f();
    for(int i=1;i<=tail;i++){
        printf("%d ",dp[i]);
    }
}