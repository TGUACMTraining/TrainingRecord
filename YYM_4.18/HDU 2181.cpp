#include<iostream>
#include<cstring>
using namespace std;
int n;
int nextnode[25][5];
int visited[25];
int path[25];
int tail;
int cnt=0;
void dfs(){

    for(int i=0;i<3;i++){
        // print();
        int nd=nextnode[path[tail-1]][i];
        if(visited[nd])continue;
        if(nd==n&&tail==20){
            cout<<cnt++<<":  ";
            for(int i=0;i<tail;i++){
                cout<<path[i]<<" ";
            }cout<<n<<endl;
            continue;
        }
        visited[nd]=1;
        path[tail++]=nd;
        dfs();
        tail--;
        visited[nd]=0;
    }
}
int main(){
    for(int i=1;i<=20;i++){
        for(int j=0;j<3;j++){
            cin>>nextnode[i][j];
        }
    }
    while(cin>>n,n){
        tail=0;
        memset(visited,0,sizeof(visited));
        memset(path,0,sizeof(path));
        path[tail++]=n;
        cnt=1;
        dfs();
    }
}