/*
直接if判断左右两端能不能连成2020 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T;
int n; 
string lis;

inline void t(){
	puts("YES\n");
	return;
}
inline void f(){
	puts("NO\n");
	return;
}

int main(){
	scanf("%d",&T);
	while(T--){
		lis.clear();
		scanf("%d",&n);
		cin>>lis;
		int len=n-1;
		if(lis[0]=='2'){
			if(lis[1]=='0'){
				if(lis[2]=='2'){
					if(lis[3]=='0') t();
					else{
						if(lis[len]=='0') t();
						else f();
					}
				}
				else{
					if(lis[len-1]=='2'&&lis[len]=='0') t();
					else f();
				}
			}
			else{
				if(lis[len-2]=='0'&&lis[len-1]=='2'&&lis[len]=='0') t();
				else f();
			}
		}
		else{
			if(lis[len-3]=='2'&&lis[len-2]=='0'&&lis[len-1]=='2'&&lis[len]=='0') t();
			else f();
		}
	}
	return 0;
}
