#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char table[10][10];
int cnt;
int n,k;
int visited[10];
void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<table[i][j];
        }cout<<endl;
    }
    cout<<endl;
}
void dfs(int at){
    for(int i=1;i<=n;i++){
        if(visited[i]==0&&table[at][i]=='#'){
            visited[i]=1;
            table[at][i]='$';
            k--;
            if(k==0){
                cnt++;
                // print();
                k++;
                table[at][i]='#';
                visited[i]=0;
                continue;
            }
            for(int depth=at+1;depth<=n-k+1;depth++){
                dfs(depth);
            }
            k++;
            table[at][i]='#';
            visited[i]=0;
        }
    }
}
int main(){
    
    while(cin>>n>>k,n!=-1&&k!=-1){
        cnt=0;
        memset(table,0,sizeof(table));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>table[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        dfs(i);
        cout<<cnt<<endl;
    }
}