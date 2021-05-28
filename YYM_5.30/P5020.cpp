#include<algorithm>
#include<cstring>
#include<iostream>  
using namespace std;
int n;
bool arr[25010];
int val[105];
void print(){
    for(int i=0;i<=val[n];i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int eq(){
    memset(arr,0,sizeof(arr));
    sort(val+1,val+n+1);
    arr[0]=true;
    int flag=n;
    for(int i=1;i<=n;i++){
        if(arr[val[i]]){flag--;}
        for(int j=1;j<=val[n];j++){
            if(j-val[i]>=0&&arr[j-val[i]])arr[j]=true;
        }
        print();
    }
    return flag;
}
int main(){
    freopen("ac.txt","w",stdout);
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