#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int num[1000100]={0};
int sum[1000100]={0};
int numbers[100010]={0};
int tail;
int main(){
    int n,cache;
    int max_=0;
    int min_=100000;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&cache);
        numbers[tail++]=cache;
        num[cache]++;
        max_=max(max_,cache);
        min_=min(min_,cache);
    }
    for(int i=0;i<max_+10;i++){
        if(num[i])
        {
            for(int j=1;j*i<=max_;j++){
                sum[j*i]+=num[i];
            }
        }
    }
    for(int i=0;i<tail;i++){
        printf("%d\n",sum[numbers[i]]-1);
    }
}