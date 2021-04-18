#include<iostream>
using namespace std;
typedef long long ll;
const int limit = (int)5.5e5;
ll sum1[limit];
ll sum2[limit];
int n=10;
void add(int x,int k){
    for(int i=x;i<=n;i+=i&-i){
        sum1[i]+=k;
        sum2[i]+=x*k;
    }
}
void range_add(int l,int r,int k){
    add(l,k);
    add(r+1,-k);
}
int query(int x){
    int ans=0;
    for(int i=x;i;i-=i&-i){
        ans+=(x-1)*sum1[i]+sum2[i];
    }
    return ans;
}
int range_query(int l,int r){
    return query(r)-query(l-1);
}
int main(){
    range_add(1,10,1);
    cout<<query(10);
}