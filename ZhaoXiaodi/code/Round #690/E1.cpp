/*
用map记录每个数字的出现次数，判断六种情况（即(a,a,a)(a,a,a+1)(a,a+1,a+1)(a,a,a+2)(a,a+2,a+2)(a,a+1,a+2)）是否成立并计算组合数。 
中间过程会爆int。 
*/ 
#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
map<int,long> m;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		m.clear();
		scanf("%d",&n);
		int ain;
		int minn=0x3f3f3f3f,maxn=-1;
		for(int i=1;i<=n;i++){
			scanf("%d",&ain);
			if(m.find(ain)!=m.end()) m[ain]++;
			else m[ain]=1;
			minn=min(minn,ain);
			maxn=max(maxn,ain);
		}
		long long ans=0;
		for(int i=minn;i<=maxn;i++){
			if(m.find(i)==m.end()) continue;
			if(m[i]>=3) ans+=(long long)m[i]*(long long)(m[i]-1)*(long long)(m[i]-2)/(long long)6;//111
			if(m.find(i+1)!=m.end()){
				if(m[i]>=2) ans+=(long long)m[i+1]*(long long)m[i]*(long long)(m[i]-1)/(long long)2;//112
				if(m[i+1]>=2) ans+=(long long)m[i]*(long long)m[i+1]*(long long)(m[i+1]-1)/(long long)2;//122
				if(m.find(i+2)!=m.end()){
					ans+=(long long)m[i]*(long long)m[i+1]*(long long)m[i+2];//123
				}
			}
			if(m.find(i+2)!=m.end()){
				if(m[i]>=2) ans+=(long long)m[i]*(long long)(m[i]-1)*(long long)m[i+2]/(long long)2;//113
				if(m[i+2]>=2) ans+=(long long)m[i]*(long long)(m[i+2]-1)*(long long)m[i+2]/(long long)2;//133
			}
		}
		printf("%lld\n",ans);
	}
}
