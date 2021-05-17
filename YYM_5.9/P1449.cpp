#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int stk[(int)10];
int tail;
char *p;
int ans;
inline bool read(){
    int x=0;
    while(!isdigit(*p)){
        switch (*p)
        {
        case '.':
            break;
        case '+':
            stk[tail-2]=stk[tail-2]+stk[tail-1];
            --tail;
            break;
        case '-':
            stk[tail-2]=stk[tail-2]-stk[tail-1];
            --tail;
            break;
        case '*':
            stk[tail-2]=stk[tail-2]*stk[tail-1];
            --tail;
            break;
        case '/':
            stk[tail-2]=stk[tail-2]/stk[tail-1];
            --tail;
            break;
        case '@':
            ans=stk[--tail];
            return false;
        }
        ++p;
    }
    while(isdigit(*p))x=x*10+(*p++&15);
    stk[tail++]=x;
    return true;
}
int main(){
    p=new char [1100];
    fread(p,1,1100,stdin);
    while(read());
    cout<<ans<<endl;
}