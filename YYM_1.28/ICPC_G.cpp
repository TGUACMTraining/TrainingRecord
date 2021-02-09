#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct number{
    unsigned long long higher;
    unsigned long long lower;
    void operator+=(number add){
        higher+=add.higher;
        lower+=add.lower;
        if(lower>=1000000000000000000){
            lower-=1000000000000000000;
            higher+=1; 
        }
    }
    number(unsigned long long h=0,unsigned long long l=0){
        higher=h;
        lower=l;
    }
    void print(){
        if(higher){
            printf("%lld%018lld",higher,lower);
        }else{
            printf("%lld",lower);
        }
    }
};
// int dp[1010][110];
number dp[1010][110];
int main(){
    memset(dp,0,sizeof(dp));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<1001;i++){
        dp[i][1]=number(0,1);
        dp[i][0]=number(0,1);
    }
    for(int j=2;j<101;j++){
        for(int i=0;i<1001;i++){
            for(int k=0;k*j<=i;k++){
                dp[i][j]+=dp[i-k*j][j-1];
            }
        }
    }
    dp[n][m].print();
}
/*
5
1 1
2 (5,1) (3,1) (1,1) 
3 (5,2) ()
*/