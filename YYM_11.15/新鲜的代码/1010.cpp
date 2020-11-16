#include<iostream>
#include<stdio.h>
using namespace std;
void breakdown(int);
int main( ){
    // for(int t=0;t<32;t++)
    // {
    //     printf("%d",(int)finger[t]);
    // }
    int n;
    cin>>n;
    breakdown(n);
    return 0;
}
void breakdown(int num)
{
    int i=1u;
    char finger[32];
    for(int t=0;t<32;t++,i=i<<1)
    {
        finger[t]=i&num?1:0;
    }
    for(int t=31;t+1;t--)
    {
        if(finger[t])
        {
            num-=1u<<t;
            if(0==t){
                printf("2(0)");
                if(num)printf("+");
            }else if(1==t){
                printf("2");
                if(num)printf("+");
            }else{
                printf("2(");
                breakdown(t);
                printf(")");
                if(num)printf("+");
            }
        }
        //cout<<"2("<<(t>2?((breakdown(finger[t])),""):((cout<<t),""))<<")+";
    }
}