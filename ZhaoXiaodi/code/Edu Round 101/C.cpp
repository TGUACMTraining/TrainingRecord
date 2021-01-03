/*
由题意知较高处位置确定后不会再受低处影响，所以按照高度降序处理每个位置能够上升的位置，最后判断是否让每个位置的板块都有相交的部分。 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,k;
int lis[200010];
int pos[200010];

bool cmp(int a,int b){
	return lis[a]>lis[b];
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&lis[i]);
			pos[i]=i;
		}
		lis[0]=lis[1];
		lis[n+1]=lis[n];
		bool flag=1;
		sort(pos+1,pos+n+1,cmp);
		for(int i=2;i<=n;i++){
			int now=pos[i];
			if(now==1){
				if(lis[now+1]-k>=lis[now]){
					flag=0;
					break;
				}
			}
			else{
				if(now==n){
					if(lis[now-1]-k>=lis[now]){
						flag=0;
						break;
					}
				}
				else{
					int add=min(k-1,max(0,max(lis[now-1]-lis[now]-k+1,lis[now+1]-lis[now]-k+1)));
					lis[now]+=add;
				}
			}
		}
		for(int i=2;i<n;i++){
			if(abs(lis[i]-lis[i-1])>=k||abs(lis[i]-lis[i+1])>=k){
				flag=0;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
//		for(int i=1;i<=n;i++) cout<<lis[i]<<" - ";
//		cout<<endl<<endl;
	}
	return 0;
}
