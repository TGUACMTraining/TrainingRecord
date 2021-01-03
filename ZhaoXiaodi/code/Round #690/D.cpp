/*
枚举可能情况选出最小情况输出。 
*/ 
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int lis[3010],n;

inline int find(int x){
    int ans=0;
	int res=0;
    int i=1;
    while(i<=n){
        res+=lis[i++];
        if(res==x){
            res=0;
            continue;
        }
        if(res>x){
        	ans=n-1;
        	return ans;
		}
        ans++;
    }
    return ans;
}

int main(){
    int T;
	scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&lis[i]);
            sum+=lis[i];
        }
        int ans=n-1;
        for(int i=1;i*i<=sum;i++){
            if(sum%i==0) ans=min(ans,min(find(i),find(sum/i)));
        }
        printf("%d\n",ans);
    }
    return 0;
}
