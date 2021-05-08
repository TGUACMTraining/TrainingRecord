#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int flag=0;
    for(auto x:s){
        if(x=='Z')flag=1;
        if(flag){if(x!='Z'){cout<<-1<<endl;return 0;}}
    }
    for(auto x:s){
        switch (x)
        {
        case 'X':
            cout<<2;
            break;
        case 'Y':
            cout<<0;
            break;
        default:
            cout<<1;
            break;
        }
    }cout<<endl;
    for(int i=0;i<s.length();i++){
        cout<<1;
    }
}