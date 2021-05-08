#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char str[40];
long long n;
int len;
long long near(long long n){
    for(long long i=1ull<<62;i!=0;i>>=1){
        if(n&i)return i;
    }return 0;
}
char ask(long long n){
    if(n<len)return str[n];
    long long newlen=near(n/len)*len;
    if(n==newlen)return ask(n-1);
    return ask(n-newlen-1);
}
int main(){
    cin>>str>>n;
    n--;
    len=strlen(str);
    // for(int i=0;i<24;i++){
    //     cout<<ask(i);
    // }
    // cout<<endl;
    cout<<ask(n)<<endl;
}