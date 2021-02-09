#include<iostream>
#include<utility>
using namespace std;
int n;
int m[110][110];
int cache[110];
int sum[110][110];
int refresh_cache_and_find_max(int begin,int end){
    int biggest=0;
    for(int i=1;i<=n;i++){
        cache[i]=m[end][i]-m[begin-1][i];
        if(cache[i-1]>0)cache[i]+=cache[i-1];
        if(cache[i]>biggest)biggest=cache[i];
    }
    return biggest;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>m[i][j];
            m[i][j]+=m[i-1][j];
        }
    }
    int biggest=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int cache=refresh_cache_and_find_max(i,j);
            if(cache>biggest)biggest=cache;
        }
    }
    cout<<biggest<<endl;
    return 0;
}