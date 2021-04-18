#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define clean(x) memset(x,0,sizeof(x))
int result[11];
int cache[11];
int pies[110000][11];
bool visited[11];
int tail;
void visit(int i){
    if(i>=0&&i<11){
        visited[i]=1;
    }
}
void refresh(int i,int t){
    if(visited[i]){
        for(int d=-1;d<=1;d++){
            if(i+d>=0&&i+d<11){
                cache[i+d]=max(result[i]+pies[t][i+d],cache[i+d]);
            }
        }
    }
}
int main(){
    int n;
    int x,t;
    while(scanf("%d",&n),n){
        clean(result);
        clean(cache);
        clean(pies);
        clean(visited);
        tail=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&t);
            pies[t][x]++;
            tail=max(t,tail);
        }
        visited[5]=1;
        for(int i=1;i<=tail;i++){
            
            for(int j=0;j<11;j++){
                refresh(j,i);
            }
            // for(int t=0;t<11;t++){
            //     cout<<result[t]<<" ";
            // }cout<<endl;
            memcpy(result,cache,sizeof(result));
            visit(5+i);
            visit(5-i);
        }
        int res=0;
        for(int i=0;i<11;i++){
            res=max(res,result[i]);
        }
        printf("%d\n",res);
    }
}