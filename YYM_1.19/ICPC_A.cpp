#include<bits/stdc++.h>
using namespace std;
void fu(int *a,int num,int jinzhi);
int refresh_sum(int *arr){
    int sum;
    sum=arr[0]+arr[1]+arr[2]+arr[3];
    return sum;
}
int main(){
    int arr[4];
    int sum;
    for(int i=1111;i<=9999;i++){
        fu(arr,i,10);
        sum=refresh_sum(arr);
        fu(arr,i,16);
        if(sum==refresh_sum(arr)){
            fu(arr,i,12);
            if(sum==refresh_sum(arr)){
                cout<<i<<endl;
            }
        }
    }
}
void fu(int *a,int num,int jinzhi){
    switch (jinzhi)
    {
    case 16:
        a[0]=num%16/1;
        a[1]=num%256/16;
        a[2]=num%4096/256;
        a[3]=num%65536/4096;
        break;
    case 12:
        a[0]=num%12/1;
        a[1]=num%144/12;
        a[2]=num%1728/144;
        a[3]=num%20736/1728;
        break;
    case 10:
        a[0]=num%10/1;
        a[1]=num%100/10;
        a[2]=num%1000/100;
        a[3]=num%10000/1000;

    }
}