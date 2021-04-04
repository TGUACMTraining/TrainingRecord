#include<iostream>
#include<cstring>
using namespace std;
int arr[(int)1.1e5];
int solved[(int)1.1e5];
int tail=1;
int main(){
    memset(arr,0x3f,sizeof(arr));
    arr[0]=0;
    int n,m;
    cin>>n>>m;
    // for(int i=1;i<=n;i++){
    //     int ti,yi;
    //     unsigned long long xi;
    //     cin>>ti>>xi>>yi;
    //     for(int index=0;index<=m;index++){
    //         if(index==0&&ti==2)continue;
    //         if(arr[index]<i){
    //             unsigned long long k=index;
    //             for(int j=0;j<=yi;j++){
    //                 if(k>m)goto flag;
    //                 if(arr[k]>i)arr[k]=i;
    //                 switch (ti)
    //                 {
    //                 case 1:
    //                     k=(xi+k*100000+99999)/100000;
    //                     break;
                    
    //                 default:
    //                     k=(xi*k+99999)/100000;
    //                     break;
    //                 }
    //             }
    //         }
    //         flag:
    //         1;
    //     }
    // }
    for(int i=1;i<=n;i++){
        int ti,yi;
        int xi;
        scanf("%d%d%d",&ti,&xi,&yi);
        int cache_tail=tail;
        for(int p=0;p<cache_tail;p++){
            int j=0;
            int index=solved[p];
            if(index==0&&ti==2)continue;
            int k=index;
            if(ti==2){j=1; k=(xi*k+99999)/100000;}
                for(;j<=yi;j++){

                    if(k>m)break;
                    if(arr[k]>i){arr[k]=i;solved[tail++]=k;}
                    switch (ti)
                    {
                    case 1:
                        k=(xi+k*100000+99999)/100000;
                        break;
                    
                    default:
                        k=(xi*k+99999)/100000;
                        break;
                    }
                }
            
        }
    }
    for(int i=1;i<=m;i++){
        if(arr[i]>200)printf("-1 ");
        else printf("%d ",arr[i]);
    }
}