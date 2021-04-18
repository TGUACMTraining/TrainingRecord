#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    bool flag=true;
    while(getline(cin,s)){
        for(int i=0;i<s.length();i++){
            switch (s[i])
            {
            case '"':
                if(flag){
                    cout<<"``";
                }else{
                    cout<<"''";
                }flag=!flag;
                break;
            
            default:
                cout<<s[i];
                break;
            }
        }cout<<endl;
    }
}