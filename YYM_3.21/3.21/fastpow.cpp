#include<cstring>
#include<iostream>
using namespace std;

const int N=2;
int cache[N][N]={{1,1},{1,0}};
int result[N][N];
int MOD=(int)(1e6+7);

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

int main(){
    for(int n=2;n<10;n++){
        cout<<endl;
        fastpow(result,n-1);
        cout<<result[0][0]<<endl;
}
}