#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<ctime>
using namespace std;
int n,m;
int arr[(int)1e4+10][(int)1e2+10];
int ind[(int)1e4+5];
bool xiaoyu(int a,int b){
    for(int i=0;i<m;i++){
        if(arr[a][i]<arr[b][i])return true;
    }
    return false;
}
struct c{
    int shuliang;
    int xiabiao;
};
    bool xiao(c b,c a){
        if(b.shuliang==a.shuliang){
            return xiaoyu(b.xiabiao,a.xiabiao);
        }else{
            return b.shuliang<a.shuliang;
        }
    }
    bool x(c b,c a){
        return xiao(a,b);
    }
c p[(int)1e4+10];
vector<int> v[(int)1e4+10];
int tail;
int main(){
    for(int i=0;i<1e4+5;i++){
        ind[i]=i;
    }
    cin>>n>>m;
    for(int i=0;i<n;i++){
        long long hash=1;
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            hash*=1234567891;
            hash+=arr[i][j];
        }
        arr[i][m]=hash;
    }
    sort(ind,ind+n,xiaoyu);
    for(int i=0;i<n;i++){
        if(arr[p[tail].xiabiao][m]!=arr[ind[i]][m]){
            p[++tail]={1,ind[i]};
        }else{
            p[tail].shuliang++;
        }
    }
    sort(p+1,p+tail+1,x);
    cout<<tail<<endl;
    for(int i=1;i<tail+1;i++){
        cout<<p[i].shuliang<<" ";
        for(int j=0;j<m;j++){
            cout<<arr[p[i].xiabiao][j]<<" ";
        }cout<<endl;
    }
}