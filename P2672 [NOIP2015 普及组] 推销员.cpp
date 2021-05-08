#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
pii arr[(int)1e5+10];
int pre[(int)1e5+10];
int suf[(int)1e5+10];
int path[(int)1e5+10];
int n;
#define dis second
#define cost first
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].dis;
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i].cost;
    }
    sort(arr+1,arr+n+1,greater<pii>());
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+arr[i].cost;
        path[i]=max(path[i-1],arr[i].dis*2);
    }
    for(int i=n;i>0;i--){
        suf[i]=max(arr[i].cost+arr[i].dis*2,suf[i+1]);
    }
    for(int i=1;i<=n;i++){
        cout<<max(pre[i]+path[i],pre[i-1]+suf[i])<<endl;
    }
}