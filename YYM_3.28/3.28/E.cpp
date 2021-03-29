#include<iostream>
#include<cstring>
using namespace std;
int dis[110][110];
int n;
int main(){
    int road;
    while(cin>>n>>road,n||road){
        memset(dis,0x3f,sizeof(dis));
            int from,to,d;
        while(road--){
            cin>>from>>to>>d;
            dis[from][to]=min(dis[from][to],d);
            dis[to][from]=dis[from][to];
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        cout<<dis[1][n]<<endl;
    }
}