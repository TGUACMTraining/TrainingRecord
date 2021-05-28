#include<cstring>
#include<iostream>
using namespace std;
int n;
int weight[110];
int sum[210];
int big[210][210];
int small[210][210];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+weight[i];
    }
    for(int i=n+1;i<=n*2;i++){
        sum[i]=sum[i-1]+weight[i-n];
    }
    memset(small,0x3f,sizeof(small));
    for(int i=1;i<=2*n;i++){
        small[i][i]=0;
    }
    for(int len=1;len<=n;len++){
        for(int from=1;from+len-1<=n*2;from++){
            int to=from+len-1;
            for(int cut=from;cut<to;cut++){
                big[from][to]=max(big[from][to],big[from][cut]+big[cut+1][to]+sum[to]-sum[from-1]);
                small[from][to]=min(small[from][to],small[from][cut]+small[cut+1][to]+sum[to]-sum[from-1]);
            }
        }
    }
    int len=n;
    int bigger=0;
    int smaller=0x3f3f3f3f;
    for(int from=1;from+len-1<=n*2;from++){
        bigger=max(big[from][from+len-1],bigger);
        smaller=min(small[from][from+len-1],smaller);
    }
    printf("%d\n%d",smaller,bigger);
}