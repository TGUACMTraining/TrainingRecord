#include<cstring>
#include<iostream>
using namespace std;

const int N=3;
int cache[N][N]={{1,1,1},{1,0,0},{0,1,0}};
int result[N][N];
int MOD=(int)(10000);

void multiply(int a[][N],int b[][N],int save[][N]){
    int c[N][N];
    memset(c,0,sizeof(c));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                c[i][j]=(c[i][j]+a[i][k]%MOD*b[k][j]%MOD)%MOD;
            }
        }
    }
    memcpy(save,c,sizeof(c));
}

void fastpow(int m[][N],int n){   
    
    if(n==0) {
        memset(m,0,sizeof(int)*N*N);
        for(int i=0;i<N;i++){
            m[i][i]=1;
        }
        return;
    }
    fastpow(m,n/2);
    multiply(m,m,m);
    if(n%2) multiply(m,cache,m);
}

void print(int m[][N] ){
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<m[i][j]<<" ";
            }cout<<endl;
        }
    }
}
int main(){
    fastpow(result,20190324);
    print(result);
}