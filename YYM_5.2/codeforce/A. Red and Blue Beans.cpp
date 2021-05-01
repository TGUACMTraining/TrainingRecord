#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    while(n--){
        long long small,big,d;
        cin>>small>>big>>d;
        if(small>big)swap(small,big);
        if(big==0){cout<<"NO"<<endl;continue;}
        long long max_=(d+1)*small;
        if(big<=max_){
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }   
}//