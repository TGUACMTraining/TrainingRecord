#include<iostream>
#include<algorithm>
using namespace std;
int nd[21][3];
int e;
bool visited[21];
int path[21];
int tail;
int cnt=0;
void dfs(int d){
    if(d==e){
        if(tail==20){
            cout<<++cnt<<":  ";
            cout<<e<<" ";
            int flag=0;
            for(int i=0;i<20;i++){
                if(flag)cout<<" ";
                flag=1;
                cout<<path[i];
            }cout<<endl;return ;}
    }
    for(int i=0;i<3;i++){
        if(!visited[nd[d][i]]){
            visited[nd[d][i]]=true;
            path[tail++]=nd[d][i];
            dfs(nd[d][i]);
            tail--;
            visited[nd[d][i]]=false;
        }
    }
}
int main(){
    while(cin>>nd[1][0],nd[1][0]){
        cin>>nd[1][1]>>nd[1][2];
        sort(&(nd[1][0]),&(nd[1][3]));
    for(int i=2;i<=20;i++){
        for(int j=0;j<3;j++){
            cin>>nd[i][j];
        }
        sort(&(nd[i][0]),&(nd[i][3]));
    }
    // for(int i=1;i<=20;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<nd[i][j];
    //     }cout<<endl;
    // }cout<<endl;
    cin>>e;
    for(int i=0;i<3;i++){
        path[tail++]=nd[e][i];
        visited[nd[e][i]]=true;
        dfs(nd[e][i]);
        tail--;
        visited[nd[e][i]]=false;
    }
    }
}