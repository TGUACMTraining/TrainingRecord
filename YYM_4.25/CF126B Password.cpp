#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
const int limit =(int )1e6+10;
char a[limit ];
char b[limit ];
int kmp[limit];
int arr[limit];
int tail;
int maxinum;
int main(){
    cin>>a+1;
    strcpy(b+1,a+2);
    b[strlen(b+1)]=0;
    int la=strlen(a+1);
    int j=0;
    for(int i=2;i<=la;i++){
        while(j&&a[j+1]!=a[i])j=kmp[j];
        if(a[j+1]==a[i])j++;
        kmp[i]=j;
    }
    int t=kmp[la];
    while(t){
        arr[tail++]=t;
        t=kmp[t];
    }
    tail++;
    reverse(arr,arr+tail);
    int lb=strlen(b+1);
    j=0;
    for(int i=1;i<=lb;i++){
        while(j&&a[j+1]!=b[i])j=kmp[j];
        if(a[j+1]==b[i])j++;
        maxinum=max(maxinum,j);
    }
    int* index=upper_bound(arr,arr+tail,maxinum)-1;

    for(int i=1;i<=*index;i++){
        cout<<a[i];
    }
    if(!*index)cout<<"Just a legend";
    cout<<endl;
}