#include<iostream>
using namespace std;
void r(int &x){
    scanf("%d",&x);
    x%=10000;
}
int main(){
    int ans,cache1,cache2;
    ans=cache1=cache2=0;
    r(cache1);
    char op;
    while(cin>>op){
        if(op=='+'){
            ans+=cache1;
            ans%=10000;
            r(cache1);
        }
        else{
            r(cache2);
            cache1*=cache2;
            cache1%=10000;            
        }
    }
    ans+=cache1;
    ans%=10000;
    cout<<ans;
}