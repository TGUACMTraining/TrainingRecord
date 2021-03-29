#include<bits/stdc++.h>
using namespace std;

int minute[150];
int ma[120][120];
int n;

int main(){

    while(true){
        memset(ma,0x3f,sizeof(ma));
        memset(minute,0,sizeof(minute));
        int m;
        if(cin>>n>>m,n||m){
            while (m--)
            {
                int x,y,t;
                cin>>x>>y>>t;
                ma[x][y]=ma[y][x]=min(ma[x][y],t);
            }
            cout<<f(n)<<endl;
        }else goto flag;
    }
    flag:
    return 0;
}