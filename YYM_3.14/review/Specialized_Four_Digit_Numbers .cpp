#include<iostream>
using namespace std;
int fun(int jinzhi,int i){
    int shi,bai,qian;
    int result;
    shi=jinzhi;
    bai=shi*shi;
    qian=shi*bai;
    result=i/qian;
    i%=qian;
    result+=i/bai;
    i%=bai;
    result+=i/shi;
    i%=shi;
    result+=i;
    return result;
}
int main(){
    for(int i=1000;i<=9999;i++){
        if(fun(10,i)==fun(16,i)&&fun(16,i)==fun(12,i)){
            cout<<i<<endl;
        }
    }
}