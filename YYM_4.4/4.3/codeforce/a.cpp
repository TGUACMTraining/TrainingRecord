#include<iostream>
using namespace std;
typedef string::iterator si;
bool dejavu(si a,si b){
    for(;a<b;a++,b--){
        if(*a!=*b)return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        int allisa=1;
        for(int i=0;i<str.length();i++){
            if(str[i]!='a'){
                allisa=0;
            }
        }
        if(allisa){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        if(*(str.end()-1)=='a'&&dejavu(str.begin(),str.end()-2)){
            cout<<str<<"a"<<endl;
        }else {
            cout<<"a"<<str<<endl;
        }
    }
}