#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[10100];
char b[10100];
int c[10100];
void f(char a[],char b[]){
    int want=0;
    for(int i=0;i<10100;i++){
        if(a[i])a[i]-='0';
        if(b[i])b[i]-='0';
        c[i]+=a[i]-b[i]-(want/=10);
        while(c[i]<0){c[i]+=10;want+=10;}
    }
    int flag=0;
    for(int i=10099;i>=0;i--){
        if(c[i])flag=1;
        if(flag)cout<<c[i];
    }
    if(!flag){
        cout<<0<<endl;
    }
}
bool bigger(){
    for(int i=10099;i>=0;i--){
        if(a[i]<b[i])return false;
        else
        if(a[i]>b[i])return true;
    }
    return true;
}
int main(){
    cin>>a>>b;
    reverse(a,a+strlen(a));
    reverse(b,b+strlen(b));
    if(bigger()){
        f(a,b);
    }else{
        cout<<"-";
        f(b,a);
    }

}