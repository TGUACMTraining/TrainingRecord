#include<iostream>
#include<cmath>
#include<time.h>
using namespace std;
int coins[11]= {1,2,4,10,20,40,100,200,400,1000,2000};
bool e(double a,double b){
    return fabs(a-b)<1e-6;
}
long long num[15][6001];
int main(){
    double value;
    int money;
    for(int i=0;i<6001;i++){
        num[0][i]=1;
    }
    for(int i=0;i<11;i++){
        num[i][1]=1;
        num[i][0]=1;
    }
    for(int i=2;i<6001;i++){
        for(int j=1;j<11;j++){
            for(int k=0;k*coins[j]<=i;k++)
            num[j][i]+=num[j-1][i-k*coins[j]];
        }
    }
    while(scanf("%lf",&value),!e(value,0)){
        printf("%6.2lf",value);
        value*=100;
        value+=0.5;
        money=value;
        money/=5;
        printf("%17lld\n",num[10][money]);
    }
}

/*
1: 1 1 1
2: 1 2 2
3: 1 2 2
4: 1 3 4
5: 1 3 4
6: 1 4 5
*/