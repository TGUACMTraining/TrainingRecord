#include<iostream>
using namespace std;
const int limit = 15;
int a[limit];
int b[limit];
int a0[limit];
int a1[limit];
int n;
int tail;
int cmp(int i,int mode){//0 == ;1 != 
    switch (mode)
    {
    case 0:
        for(;i>=0;i--){
            if(a[i]!=b[i])return i;
        }
        break;
    
    default:
        for(;i>=0;i--){
            if(a[i]==b[i])return i;
        }
        break;
    }
    return -1;
}
int first_equal(int i){
    for(;i<n;i++){
        if(a0[i]==a1[i])return i;
    }
    return -1;
}
void caculate(){
    int index;
    int mode=0;
    int equal;
    while(1){
        index==cmp(n-1,mode);
        if(index==-1){cout<<"YES"<<endl;return ;}
        else{
            equal= first_equal(index);
            if(equal==-1){
                cout<<"NO"<<endl;
                return ;
            }
            n=equal;
            mode=0;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        getchar();
        int cache;
        int tial0=0,tail1=0;
        a[0]=getchar()-'0';
        if(a[0]){
            a1[0]=1;
        }else a0[0]=1;
        for(int i=1;i<n;i++){
            a[i]=getchar()-'0';
            if(a[i]){
                a1[i]=a1[i-1]+1;
                a0[i]=a0[i-1];
            }else{
                a0[i]=a0[i-1]+1;
                a1[i]=a1[i-1];
            }
        }getchar();
        for(int i=1;i<n;i++){
            b[i]=getchar()-'0';   
        }
        int mode=0;
        caculate();
    }
}