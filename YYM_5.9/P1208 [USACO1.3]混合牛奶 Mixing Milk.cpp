#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
pair<int,int> arr[5010];
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>arr[i].first>>arr[i].second;
        arr[i].second=-arr[i].second;
    }
    sort(arr,arr+m);
    int ans=0;
    for(int i=0;i<m;i++){
        if(n+arr[i].second<=0){
            ans+=n*arr[i].first;
            break;
        }
        else {
            ans-=arr[i].first*arr[i].second;
            n+=arr[i].second;
        }
    }
    cout<<ans<<endl;
}