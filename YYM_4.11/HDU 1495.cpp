#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int L=110;
bool visited[L][L][L];
int cola[3];
inline bool equal(int i,int j,int k){
    return (i==j&&!k)||(j==k&&!i)||(k==i&&!j);
}
int q[L*L*L+100][3];
int step[L*L*L+100];
int tail,head; 
inline void pour(int &i,int &j,int i_l,int j_l){
    if(j_l-j<=i){
        i=i-j_l+j;
        j=j_l;
    }else{
        j+=i;
        i=0;
    }
}
int arr[6][2]={
    {0,1},
    {1,2},
    {2,0},
    {1,0},
    {2,1},
    {0,2},
};
int bfs(){
    while(tail!=head){
            for(int temp=0;temp<6;temp++){
                int i=arr[temp][0];
                int j=arr[temp][1];
                int cache[3];
                if(q[tail][i]==0)continue;
                for(int p=0;p<3;p++){
                    cache[p]=q[tail][p];
                }
                pour(cache[i],cache[j],cola[i],cola[j]);
                if(!visited[cache[0]][cache[1]][cache[2]]){
                    visited[cache[0]][cache[1]][cache[2]]=true;
                    for(int p=0;p<3;p++){
                        q[head][p]=cache[p];
                    }
                    step[head]=step[tail]+1;
                    head++;
                    // print();
                    if(equal(cache[0],cache[1],cache[2])){
                        return step[head-1];
                    }
                }
            }
        tail++;
    }
    return 0;
}
int main(){

    while(cin>>cola[0]>>cola[1]>>cola[2],cola[0]||cola[1]||cola[2]){
        head=tail=0;
        memset(visited,0,sizeof(visited));
        q[head][0]=cola[0];
        visited[cola[0]][0][0]=true;
        head++;
        int flag=bfs();
        if(flag){
            cout<<flag<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
}