#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
pii arr[5100];
int n,m;
bool better(pii a,pii b){
    if(a.first==b.first)return a.second<b.second;
    else return a.first>b.first;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i].second>>arr[i].first;
    }
    sort(arr,arr+n,better);
    // cout<<m<<endl;
    m=(int)(m*(1.5));
    // cout<<m<<endl;
    int score=arr[m-1].first;
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].second<<" "<<arr[i].first<<endl;
    // }
    int select=upper_bound(arr,arr+n,pair<int,int>(score,10000),better)-arr;
    cout<<arr[select-1].first<<" "<<select<<endl;
    for(int i=0;i<select;i++){
        cout<<arr[i].second<<" "<<arr[i].first<<endl;
    }
}