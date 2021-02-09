#include<cstdio>
#include<iostream>
using namespace std;
int gcdEx(int a,int b,int*x,int*y)
{
    if(b==0)
    {
        *x=1,*y=0 ;
        return a ;
    }
    else 
    {
        int r=gcdEx(b,a%b,x,y);
        /* r = GCD(a, b) = GCD(b, a%b) */
        int t=*x ;
        *x=*y ;
        *y=t-a/b**y ;
        return r ;
    }
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        int x,y;
        x=y=1;
        int cache=gcdEx(n,m,&x,&y);
        cout<<x<<" "<<y<<" "<<cache<<endl;
    }
}