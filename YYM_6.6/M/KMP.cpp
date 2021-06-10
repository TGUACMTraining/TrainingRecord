#include<iostream>
#include<cstring>

using namespace std;
int la,lb;
const int lim=(int )1e6+10;
char a[lim],b[lim];
int kmp[lim];
int main(){
    cin>>a+1;
    cin>>b+1;
    int j=0;
    la=strlen(a+1);
    lb=strlen(b+1);
    for(int i=2;i<=lb;i++){
        while (j&&b[j+1]!=b[i])
        {
            j=kmp[j];
        }
        if(b[j+1]==b[i])j++;
        kmp[i]=j;
    }
    j=0;
    for(int i=1;i<=la;i++){
        while (j&&b[j+1]!=a[i])
        {
            j=kmp[j];
        }
        if(b[j+1]==a[i])j++;
        if(j==lb){
            cout<<i-j+1<<endl;
            j=kmp[j];
        }
    }
    for(int i=1;i<=lb;i++){
        cout<<kmp[i]<<" ";
    }cout<<endl;
    return 0;
}