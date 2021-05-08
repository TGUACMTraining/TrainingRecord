#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[510];
char b[510];
int c[510];
int main(){
    cin>>a>>b;
    reverse(a,a+strlen(a));
    reverse(b,b+strlen(b));
    for(int i=0;i<510;i++){
        if(a[i])a[i]-='0';
        if(b[i])b[i]-='0';
        c[i]+=a[i]+b[i];
        if(c[i]/10){c[i+1]+=c[i]/10;c[i]%=10;}
    }
    int flag=0;
    for(int i=509;i>=0;i--){
        if(c[i])flag=1;
        if(flag)cout<<c[i];
    }
    if(!flag)cout<<0<<endl;
}