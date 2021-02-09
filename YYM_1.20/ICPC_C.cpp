#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main(){
    while(1){
        int number[1005]={0};
        int end=-1;
        cin>>number[++end];
        if(number[0]){

            while(cin>>number[++end],number[end]);
            end--;
            for(int i=1;i<=end;i++){
                number[i]-=number[0];
                if(number[i]<0)number[i]=-number[i];
                if(number[i]==0)number[i]=number[0];
            }
            for(int i=2;i<=end;i++){
                number[i]=gcd(number[i],number[i-1]);
            }
            cout<<number[end]<<endl;

        }else{
            break;
        }
    }

}