#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int a_len,b_len;
char a[50],b[50];
int f(int a_begin,int a_end,int b_begin){
    for(int i=a_begin;i<a_end;i++){
        int change=i-a_begin;
        if(a[i]!=b[b_begin+change])return 0;
    }
    return 1;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        scanf("%s%s",a,b);
        int ans=1000000000;
        a_len=strlen(a),b_len=strlen(b);
        for(int i=0;i<a_len;i++){
            for(int j=1;j+i<=a_len;j++){
                for(int k=0;k<b_len;k++){
                    if(f(i,i+j,k))ans=min(ans,a_len-j+b_len-j);
                }
            }
        }
        if(ans==1000000000)ans=a_len+b_len;
        cout<<ans<<endl;
    }
}