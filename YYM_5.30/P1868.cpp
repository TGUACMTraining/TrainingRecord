#include<algorithm>
#include<iostream>
using namespace std;
struct range
{
    int l,r;
}arr[(int)1.5e5+10];
int dp[(int)1.5e5+10];
int rt[(int)1.5e5+10];
int head;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&arr[i].l,&arr[i].r);
        ++arr[i].l;
        ++arr[i].r;
    }
    auto cmp=[](range a,range b)->bool{
        return a.r<b.r;
    };
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++){
        if(rt[head]!=arr[i].r){
            head++;
            rt[head]=arr[i].r;
        }
        int Index=upper_bound(rt,rt+head,arr[i].l)-rt;
        while(rt[Index]>=arr[i].l)--Index;
        dp[head]=max(dp[head-1],dp[head]);
        dp[head]=max(dp[head],dp[Index]+arr[i].r-arr[i].l+1);
    }
    printf("%d",dp[head]);
}