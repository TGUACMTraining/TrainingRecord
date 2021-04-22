#include<iostream>
#include<cstring>
using namespace std;
int n,m,k;
int arr[1010];
int visited[1010];
int tail=-1;
bool judge(){
    int need=1;
    while(1){
        while(visited[need]){
            if(arr[tail]==need){need++;tail--;if(need==n+1)return true;}
            else return false;
        }
        int p;
        cin>>p;
        if(p==need){need++;}
        else{
            arr[++tail]=p;
            visited[p]=1;
            if(tail==m)return false;
        }
        if(need==n+1)return true;
    }
}
int main(){
    cin>>n>>m>>k;
    while(k--){
        memset(visited,0,sizeof(visited));
        memset(arr,0,sizeof(arr));
        tail=-1;
        if(judge())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}