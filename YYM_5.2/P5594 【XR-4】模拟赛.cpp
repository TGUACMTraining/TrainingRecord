#include<iostream>
using namespace std;
bool arr[1010][1010];
int n,m,k;
int main(){
    cin>>n>>m>>k;
    while(n--){
        for(int i=1;i<=m;i++){
            int cache;
            cin>>cache;
            arr[cache][i]=true;
        }
    }
    for(int i=1;i<=k;i++){
        int cnt=0;
        for(int j=1;j<=m;j++){
            cnt+=(arr[i][j]?1:0);
        }
        cout<<cnt<<" ";
    }
}