#include<iostream>
using namespace std;
#define dp(x,y) ans[(x)%2][y]
int main(){
    int N,M;
    cin>>N>>M;
    int *value=new int [N+1];
    int *weight=new int [N+1];
    for(int i=1;i<=N;i++){
        cin>>weight[i];
        cin>>value[i];
    }
    int ans[2][13000]={0};
    int result=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(j-weight[i]>=0)
            dp(i,j)=max(dp(i-1,j),dp(i-1,j-weight[i])+value[i]);
            else
            {
                dp(i,j)=dp(i-1,j);
            }
            result=max(result,dp(i,j));
        }
    }
    cout<<result<<endl;
}