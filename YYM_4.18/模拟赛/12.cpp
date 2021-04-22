#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int dis[250][250];
int path[250];
int tail;
long long road(){
    // int from=path[1];
    // long long res=dis[0][from];
    // for(int i=2;i<=tail;i++){
    //     int d=dis[from][path[i]];
    //     if(d==-1)return -1;
    //     res+=d;
    //     from=path[i];
    // }
    // res+=dis[from][0];
    // return res;
    int from=0;
    long long res=0;
    for(int i=1;i<=tail;i++){
        int d=dis[from][path[i]];
        if(d==-1)return -1;
        res+=d;
        from=path[i];
    }
    return res;
}
int main(){
    cin>>n>>m;
    memset(dis,-1,sizeof(dis));
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        dis[a][b]=dis[b][a]=c;
    }
    int k;
    cin>>k;
    int small=0x3f3f3f3f;
    int cnt=0;
    int x,y;
    int out=0;
    while(k--){
        cnt++;
        cin>>tail;
        for(int i=1;i<=tail;i++){
            cin>>path[i];
        }
        if(tail!=n)continue;
        path[++tail]=0;
        y=road();
        if(y==-1)out--;
        else
        if(small>y){small=y;x=cnt;}
        out++;
    }
    cout<<out<<endl;
    cout<<x<<" "<<small<<endl;
}