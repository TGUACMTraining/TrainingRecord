#include<iostream>
#include<algorithm>
using namespace std;
int ope[2];
enum{jia,jian,cheng,chu};
int arr[3];
int fl=1;
int uni(int a,int b,int op){
    switch (op)
    {
    case 0:
        return a+b;
    case 1:
        return a-b;
    case 2:
        return a*b;
    case 3:
        if(b==0){fl=0;return 0;}
        return a/b;
    }
}
int ret(){
    int res=0;
    if(ope[1]==2||ope[1]==3){
        res+=uni(arr[1],arr[2],ope[1]);
        res+=uni(arr[0],res,ope[0]);
    }else{
        res=uni(uni(arr[0],arr[1],ope[0]),arr[2],ope[1]);
    }
    if(fl==0)return 0;
    return res;
}
bool f(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            ope[0]=i;
            ope[1]=j;
            fl=1;
            if(ret()==-157296){
                return true;
            }
        }
    }
    return false;
}
char re_c(int n){
    switch (n)
    {
    case 0:
        return '+';
    case 1:
        return '-';
    case 2:
        return '*';
    case 3:
        return '/';
    }
}
int main(){
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }sort(arr,arr+3);
    int flag=1;
    do{
        if(f()){
            cout<<arr[0]<<re_c(ope[0])<<arr[1]<<re_c(ope[1])<<arr[2];
            flag=0;
        }
    }while(next_permutation(arr,arr+3));
    if(flag){
        cout<<"No"<<endl;
    }
}