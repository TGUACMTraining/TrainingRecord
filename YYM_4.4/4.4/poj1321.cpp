#include<iostream>
using namespace std;
char table[10][10];
int cnt;
int n,k;
int visited[10];
#define backward \
k++;\
visited[i]=0;
#define forward \
k--;\
visited[i]=1;
void dfs(int at){
    for(int i=1;i<=n;i++){
        if(table[at][i]=='#'&&visited[i]==0){
            forward
            if(k==0){
                cnt++;
                backward
                continue;
            }
            for(int depth=at+1;depth<=n-k+1;depth++){
                dfs(depth);
            }
            backward
        }
    }
}
int main(){
    while(cin>>n>>k,n!=-1&&k!=-1){
        cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>table[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            dfs(i);
        }
        cout<<cnt<<endl;
    }
}