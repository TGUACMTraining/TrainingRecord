#include<iostream>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j;j/=10){
            if(j%10==x)cnt++;
        }
    }
    cout<<cnt;
}