#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string str1,str2;
bool cmp(int i){
    for(int d=0;d<str2.length();d++){
        if(str1[i+d]!=str2[d])return false;
    }
    return true;
}
int main(){
    while (cin>>str1,str1!="#")
    {
        cin>>str2;
        int cnt=0;
        for(int i=0;i<=str1.length()-str2.length();i++){
            if(cmp(i)){
                cnt++;
                i+=str2.length()-1;
            }
        }
        cout<<cnt<<endl;
    }
    
}