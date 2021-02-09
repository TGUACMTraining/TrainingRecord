#include<cstdio>
#include<iostream>
using namespace std;
int f(int m,int n){   //m^n
    if(n==0) return 1;
    if(n==1) return m;
    int temp=f(m,n/2);
    return (n%2==0 ? 1 : m)*temp*temp;
}
int main(){
    int x;
    while(~scanf("%d",&x)){
        int n=0;
        int *a=new int [100000];
        do{
            cin>>a[n++];
        }while(getchar()!='\n');
        int ans=0;
        n--;
        for(int i=1;i<=n;i++){
            ans+=a[n-i]*i*f(x,i-1);
        }
        cout<<ans<<endl;
    }
}