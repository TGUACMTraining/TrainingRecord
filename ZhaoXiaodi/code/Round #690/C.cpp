/*
�����ų�����45������ 
����С����Ҫ���������ֿ�ʼ�жϣ�����9��1�ж��ܷ��������Ȼ����������� 
*/ 
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int T;
int n;


int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n>45) puts("-1");
		else{
			stack<int> s;
			int i=9;
			while(n){
				if(n-i>=0){
					s.push(i);
					n-=i;
				}
				i--;
			}
			while(!s.empty()){
				printf("%d",s.top());
				s.pop();
			}
		}
		printf("\n");
	}
	return 0;
} 
