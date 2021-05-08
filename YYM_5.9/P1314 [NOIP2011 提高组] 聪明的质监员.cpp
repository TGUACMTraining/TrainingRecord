#include<iostream>
using namespace std;
const int limit=(int)2e5+10;
int w[limit],v[limit];
long long sw[limit],sv[limit];
int n,m;
long long s;
int l[limit],r[limit];
long long sum;
bool sgmy(int W){
    for(int i=1;i<=n;i++){
        if(w[i]>W){
            sw[i]=sw[i-1]+1;
            sv[i]=sv[i-1]+v[i];
        }else{
            sw[i]=sw[i-1];
            sv[i]=sv[i-1];
        }
    }
    long long ans=0;
    for(int i=0;i<m;i++){
        ans+=(sw[r[i]]-sw[l[i]-1])*(sv[r[i]]-sv[l[i]-1]);
    }
    return (sum=ans)>s;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>s;
    int left,right;
    left=2147483647;
    right=-1;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
        left=min(w[i],left);
        right=max(right,w[i]);
    }
    left-=1;
    right+=2;
    for(int i=0;i<m;i++){
        cin>>l[i]>>r[i];
    }
    long long ans=0x3f3f3f3f3f3f3f3f;
    while(left<=right){
        int mid=(left+right)/2;
        if(sgmy(mid)){
            left=mid+1;
        }else{
            right=mid-1;
        }
        ans=min(ans,llabs(sum-s));
    }
    cout<<ans<<endl;
}
// 根据题目给的查询方式确定输入时从零开始还是从一开始