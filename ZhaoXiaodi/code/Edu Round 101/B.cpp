/*
取混合后前缀和最大，即分别取两个数列最大前缀和之和。 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,max1,max2,tot,a;
		max1=max2=tot=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			tot+=a;
			max1=max(max1,tot);
		}
		scanf("%d",&n);
		tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			tot+=a;
			max2=max(max2,tot);
		}
		printf("%d\n",max1+max2);	
	}
	return 0;
} 
