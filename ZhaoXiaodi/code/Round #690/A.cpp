/*
˫��ָ�룬ÿ�����������ߺ��ұߣ�ָ���������ƶ�ֱ������������ 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int lis[310];
int n,T;
void init(){
	memset(lis,0,sizeof(lis));
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&lis[i]);
		for(int i=1,j=n;i<=j;i++,j--){
			if(i==j) printf("%d",lis[i]);
			else{
				printf("%d ",lis[i]);
				printf("%d ",lis[j]);
			}
		}
		printf("\n");
	}
	return 0;
} 
