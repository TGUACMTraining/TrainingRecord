#include<iostream>
using namespace std;
int jiecheng[1200];
int mod=1000000007;
int main(){
    jiecheng[0]=jiecheng[1]=1;
    for(int i=1;i<1200;i++){
        jiecheng[i]=jiecheng[i-1]*i;
        jiecheng[i]%=mod;
        cout<<jiecheng[i]<<endl;
    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int c;
        cin>>c;
        n-=(c+1);
    }
    cout<<jiecheng[n+1]/((jiecheng[m]*jiecheng[n+1-m])%mod)<<endl;
}