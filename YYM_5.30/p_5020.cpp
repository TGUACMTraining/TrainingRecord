#include<algorithm>
#include<cstring>
#include<iostream>  
using namespace std;
int n;
bool arr[105][25010];
int val[105];

int eq(){
    memset(arr,0,sizeof(arr));
    sort(val+1,val+n+1);
    for(int i=0;i<=n;i++)arr[i][0]=true;
    int flag=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=val[n];j++){
            if(arr[i-1][j])arr[i][j]=true;
        }
        if(arr[i][val[i]]){flag--;continue;}
        for(int j=1;j<=val[n];j++){
            if(j-val[i]>=0&&(arr[i-1][j-val[i]]||arr[i][j-val[i]]))
            arr[i][j]=true;
        }
    }
    return flag;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&val[i]);
        }
        printf("%d\n",eq());
    }
}