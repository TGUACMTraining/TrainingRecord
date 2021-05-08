#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<pair<int,int> >mqz[510];
int sort_index[510];
bool cmp(int a,int b){
    return (mqz[a])[2].first>(mqz[b])[2].first;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int m;
            cin>>m;
            mqz[i].push_back({m,j});
        }
        sort(mqz[i].begin(),mqz[i].end(),greater<pair<int,int> >());
    }
    for(int i=0;i<510;i++){
        sort_index[i]=i;
    }
    sort(sort_index+1,sort_index+n,cmp);
    for(int i=1;i<n;i++){

    }
}