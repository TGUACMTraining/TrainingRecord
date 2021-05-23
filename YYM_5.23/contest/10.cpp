#include<sstream>
#include<iostream> 
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        if(str[0]=='-'){
            cout<<0<<endl;
        }else{
            int a,b;
            char c;
            stringstream ss;
            ss<<str;
            ss>>a>>c>>b;
            cout<<a+b*20<<endl;
        }
    }
}