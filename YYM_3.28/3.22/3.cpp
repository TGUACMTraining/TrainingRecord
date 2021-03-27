#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    if(a==b){
            printf("YES");
        }else{
            printf("NO");
        }
    while(cin>>a>>b){
        cout<<"\n";
        if(a==b){
            printf("YES");
        }else{
            printf("NO");
        }
    }
}
