#include<iostream>
using namespace std;
int re(int mode,int     n){
    int res=0;
    n*=mode;
    while (n)
    {
        res+=n%10;
        n/=10;
    }
    return res;
}
int arr[8]={2,3,4,5,6,7,8,9 };
int main(){
    int n;
    cin>>n;
    while(n--){
        int test;
        cin>>test;

        int p=re(arr[0],test);
        int flag=1;
        for(int i=1;i<8;i++){
            if(re(arr[i],test)!=p)flag=0;
        }
        if(flag){
            cout<<p<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}