#include<bits/stdc++.h>
using namespace std;
int n,m;
int *arr;
int  num(int l,int r);
int main(){
    cin>>n>>m;
    arr=new int [n+1];
    int max=0;
    unsigned long long sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>max)max=arr[i];
        sum += arr[i];
    }arr[n]=0;
    cout<<num(max,sum)<<endl;
    return 0;

}
int  num(int l,int r){
    if(l==r){return l;}
    if(r-l==1){
        int mid=(l+r)>>1;
        int flag=0;
        int real_section=0;
        unsigned long long sum_cache=0;
        for(int i=0;i<n;i++){
            sum_cache+=arr[i];
            if(sum_cache+arr[i+1]>mid){
                real_section++;
                if(real_section>m-1){
                    flag=1;
                    break;
                }
                sum_cache=0;
            }

        }
        if(flag==0){return l;}
        if(flag==1){return r;}
    }
    int mid=(l+r)>>1;
    int flag=0;
    int real_section=0;
    unsigned long long sum_cache=0;
    for(int i=0;i<n;i++){
        sum_cache+=arr[i];
        if(sum_cache+arr[i+1]>mid){
            real_section++;
            if(real_section>m-1){
                flag=1;
                break;
            }
            sum_cache=0;
        }

    }
    if(flag==1){return num(mid,r);}
    else{return num(l,mid);}
}