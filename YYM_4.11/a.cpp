#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k;
char m[10][10];
int visited[10];
int cnt;
void print(){
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m[i][j];
        }cout<<endl;
    }cout<<endl;
}
void dfs(int i){
    for(int index=0;index<n;index++){
        if(m[i][index]=='#'&&visited[index]==0){
            k--;
            if(k==0){cnt++;}
            m[i][index]='@';
            visited[index]=1;
            for(int at=i+1;at<n-k+1;at++){
                dfs(at);
            }
            k++;
            m[i][index]='#';
            visited[index]=0;
        }
    }
}
int main(){
    while(cin>>n>>k,n!=-1&&k!=-1)
    {
        cnt=0;
        memset(m,0,sizeof(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>m[i][j];
            }
        }
        for(int i=0;i<n-k+1;i++){
            dfs(i);
        }
        cout<<cnt<<endl;
    }

}