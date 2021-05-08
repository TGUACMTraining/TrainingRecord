#include<iostream>  
#include<algorithm>
#include<cstring>
using namespace std;
char a[2010],b[2010];
long long c[5000],lena,lenb;
int main(){
    cin>>a>>b;
    lena=strlen(a),lenb=strlen(b);
    reverse(a,a+lena);
    reverse(b,b+lenb);
    for(int i=0;i<lena||i<lenb;i++){
        if(a[i])a[i]-='0';
        if(b[i])b[i]-='0';
    }
    for(int i=0;i<lena;i++){
        for(int j=0;j<lenb;j++){
            c[i+j]+=a[i]*b[j];
        }
    }
    for(int i=0;i<4500;i++){
        if(c[i]/10)c[i+1]+=c[i]/10,c[i]%=10;
    }
    int flag=0;
    for(int i=4200;i>=0;i--){
        if(c[i])flag=1;
        if(flag)cout<<c[i];
    }
    if(flag==0)cout<<0<<endl;
}