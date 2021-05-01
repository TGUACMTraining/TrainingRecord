#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int tail=s.size();
    for(tail--;tail>=0;tail--){
        cout<<s[tail];
    }
}