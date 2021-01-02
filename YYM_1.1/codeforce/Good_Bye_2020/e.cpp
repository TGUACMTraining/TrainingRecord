#include<bits/stdc++.h>
using namespace std;
const unsigned long long  mod=1e9+7;
int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int len;
        cin>>len;
        unsigned long long  *arr=new unsigned long long  [len];
        for(int i=0;i<len;i++){
            cin>>arr[len];
        }
        unsigned long long  ans;
        for(int i=0;i<len;i++){
            unsigned long long  and_=0;
            for(int j=0;j<len;j++){
                and_+=arr[j]&arr[i];
                and_%=mod;
            }
            unsigned long long  or_=0;
            for(int j=0;j<len;j++){
                or_+=arr[j]|arr[i];
                or_%=mod;
            }
            ans+=and_*or_%mod;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}