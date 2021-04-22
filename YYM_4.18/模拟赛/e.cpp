#include<iostream>
#include<string>
using namespace std;
string s;
int ss(int i){
    int j;
    for(j=i;j<s.length()&&s[j]=='6';j++){
    }
    return j-i;
}
int main(){
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]=='6'){
            int n=ss(i);
            if(n>9){
                cout<<"27";
                i+=n;
            }else
            if(n>3)
                {
                    cout<<"9";
                    i+=n;
                }
        }cout<<s[i];
    }

}