#include<iostream>
#include<cstring>
using namespace std;
int num[200];
int n;
int tail;
bool judge(){
    int res=0;
    for(int i=tail;i>=0;i--){
        res*=10;
        res+=num[i];
        res%=n;
    }
    return res==0?true:false;
}
void add_one(){
    num[0]++;
    for(int i=0;i<100;i++){
        if(num[i]==2){
            num[i]=0;
            num[i+1]++;
            tail=max(tail,i+1);
        }else break;
    }
}
int main(){
    while(cin>>n,n){
        memset(num,0,sizeof(num));
        tail=0;
        while(add_one(),1){
            if(judge()){
                break;
            }
        }
        int flag=0;
        for(int i=99;i>=0;i--){
            if(num[i])flag=1;
            if(flag){
                cout<<num[i];
            }
        }cout<<endl;
    }
}