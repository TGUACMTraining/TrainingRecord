/*
��Ϊֻ��һ�����ţ�����ֱ���ж����Ų������������
1.����+�ʺ�����Ϊ������ 
2.�����������ʱΪ�������������Ҷ�ʱΪ�������� 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		string lis;
		cin>>lis;
		if(lis.length()%2==1){
			printf("NO\n");
			continue;
		}
		if(lis[0]==')'||lis[lis.length()-1]=='(') printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
