#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int num[11000];
int tail;
char c[1100];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        memset(num,0,sizeof(num));
        memset(c,0,sizeof(c));
        tail=0;
        string str;
        cin>>str;
        int len=str.length();
        for(int i=0;i<len;i++){
            if(c[tail]==str[i])num[tail]++;
            else{c[++tail]=str[i];num[tail]++;}
        }
        for(int i=1;i<=tail;i++){
            if(num[i]==1)cout<<c[i];
            else{cout<<num[i]<<c[i];}
        }cout<<endl;
    }
    
}