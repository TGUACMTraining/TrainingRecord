#include<bits/stdc++.h>
using namespace std;
int n,i,cnt;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n*n;i++){
		if(i%n==1&&i!=1){
			printf("\n");	//������˱�Ե�ͻ��� 
		}
		if(i<10){
			printf("0");	//���С��10�����0	
		}
		printf("%d",i);	//������� 
	}
	printf("\n\n");	//�м�Ŀ��к����һ�������εĻ���
	i=2*n;
	while(i>0){//����ʣ��Ŀ�λ�ж� 
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
