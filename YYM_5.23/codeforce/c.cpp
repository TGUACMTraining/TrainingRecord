#include<iostream>
#include<map>
using namespace std;
map<int,int>m;
long long f(){
    int n;
    cin>>n;
    m.clear();
    while(n--){
        int cache;
        cin>>cache;
        m[cache]++;
    }
    long long ans=0;
    for(auto ind:m){
        if(ind.second==1)continue;
        for(int i=2;i<=ind.second;i++){
            ans+=i*(i-1)*(ind.second-i+1)/2;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<f()<<endl;
    }
}