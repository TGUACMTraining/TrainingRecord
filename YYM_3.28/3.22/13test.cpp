#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
int arr[50];
int ans;
int tr[50];
bool xiaoyu(int a,int b){
    if(a>b)return true;
    else return false;
}
void dfs(int step,int head,int tail){
    if(step==-1){
        int last=0;
        for(int i=0;i<tail;i++){
            if(tr[i]){
                ans+=(arr[i]-last)*(arr[i]-last);
            }
        }
        ans+=100;

        return;
    }
    for(int i=head;i<tail-step;i++){
        tr[i]=1;
        dfs(step-1,i+1,tail);
        tr[i]=0;
    }
}
int main(){
    
    int T;
    cin>>T;
    while(T--){
        int n;
        int m;
        cin>>n>>m;
        ans=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n,xiaoyu);
        cout<<ans<<endl;

    }

}