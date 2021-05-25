#include<algorithm>
#include<iostream>
using namespace std;
int arr[(int)1e5+10];
int a1[(int)1e5+10];
int a2[(int)1e5+10];
int n;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int f1(){
    int t=0;
    for(int i=1;i<=n;i++){
        int k=upper_bound(a1+0,a1+t,arr[i],greater<int>())-a1;
        a1[k]=arr[i];
        if(k==t)t++;
        // print(a1,t);
    }
    return t;
}
int f2(){
    int t=0;
    for(int i=1;i<=n;i++){
        int k=lower_bound(a2+0,a2+t,arr[i])-a2;
        a2[k]=arr[i];
        if(k==t)t++;
        // print(a2,t);
    }
    return t;
}

int main(){
    while(~scanf("%d",&arr[++n]));
    n--;
    cout<<f1()<<endl<<f2();
} 