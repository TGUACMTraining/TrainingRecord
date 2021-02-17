#include<bits/stdc++.h>
using namespace std;
int n,i,cnt;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n*n;i++){
		if(i%n==1&&i!=1){
			printf("\n");	//如果到了边缘就换行 
		}
		if(i<10){
			printf("0");	//如果小于10就输出0	
		}
		printf("%d",i);	//输出数字 
	}
	printf("\n\n");	//中间的空行和最后一行正方形的换行
	i=2*n;
	while(i>0){//按照剩余的空位判断 
		i-=2;
		for(int j=0;j<i;j++){
			printf(" ");
		}
		for(int j=0;j<(2*n-i)/2;j++){
			cnt++;
			if(cnt<10){
				printf("0");
			}
			printf("%d",cnt);
		}
		printf("\n");
	}
    return 0;
} 
