#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        ios::sync_with_stdio(0);
        int a;
        cin>>a;
        if(a%6)cout<<"October wins!"<<endl;
        else cout<<"Roy wins!"<<endl;
    }
}