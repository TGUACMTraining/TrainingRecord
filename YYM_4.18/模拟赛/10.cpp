#include<iostream>
using namespace std;
int arr[(int)2e5+10];
bool judge(int a,int b,int c){
    int flag=1;
    flag=flag&&a+b>c;
    flag=flag&&b+c>a;
    flag=flag&&c+a>b;
    return flag;
}
int main(){
    int n,p;
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        scanf("%d",arr+i);
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i==j)continue;
            if(judge(p,arr[i],arr[j])){cnt++;}
        }
    }
    // cout<<judge(30,16,35)<<endl;
    cout<<cnt<<endl;
}