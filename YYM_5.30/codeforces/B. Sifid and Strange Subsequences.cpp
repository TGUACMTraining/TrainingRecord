#include<algorithm>
#include<iostream>
using namespace std;

char *p;
// void read(int &x){
//     x=0;
//     int flag=1;
//     while(!isdigit(*p)){((*p++)=='-')&&(flag=-1);}
//     while(isdigit(*p))x=(x<<3)+(x<<1)+(*p++&15);
//     x*=flag;
// }
void read(int &x)
{
    scanf("%d",&x);
}
int n;
const int limit=(int)1e5+10;
int arr[limit];
int len[limit];
int main(){
    int t;
    // p=new char [20*1024*1024];
    // fread(p,1,20*1024*1024,stdin);
    read(t);
    while(t--){
        read(n);
        for(int i=0;i<n;i++){
            read(arr[i]);
        }
        if(n==1){
            printf("%d\n",1);
            continue;
        }
        sort(arr,arr+n);
        if(arr[n-1]<=0)printf("%d\n",n);
        else {
            int dif=arr[1]-arr[0];
            for(int i=1;arr[i]<=0;i++){
                dif=min(dif,arr[i]-arr[i-1]);
            }
            int ans=upper_bound(arr,arr+n,0)-arr;
            if(*upper_bound(arr,arr+n,0)<=dif){
                ans++;
            }
            ans=max(ans,1);
            printf("%d\n",ans);
        }
    }
}