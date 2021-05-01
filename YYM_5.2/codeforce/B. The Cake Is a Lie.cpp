#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char arr[110][110][(int)1e4+10];
bool go(int x,int y,int k){
    if(arr[x][y][k]!=-1)return arr[x][y][k];
    if(x<=0||y<=0)return 0;
    if(go(x-1,y,k-y)||go(x,y-1,k-x))arr[x][y][k]=1;
    else arr[x][y][k]=0;
    return arr[x][y][k];
}
int main(){
    memset(arr,-1,sizeof(arr));
    arr[1][1][0]=1;
    int t;
    cin>>t;
    while(t--){
    int x,y,k;
    cin>>x>>y>>k;
    if(go(x,y,k)){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;}
}