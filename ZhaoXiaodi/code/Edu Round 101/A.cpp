/*
因为只有一对括号，所以直接判断括号不符合情况即：
1.括号+问号数量为奇数； 
2.括号在最左端时为‘）’和在最右端时为‘（’。 
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
