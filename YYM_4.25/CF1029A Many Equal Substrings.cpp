#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
    int t,n;
    char str[60]={0};
    cin>>t>>n;
    for(int i=1;i<=t;i++){
        cin>>str[i];
    }
    int kmp[60]={0};
    memset(kmp,0,sizeof(kmp));
    for(int i=2,j=0;i<=t;i++){
        while(j&&str[i]!=str[j+1])j=kmp[j];
        if(str[i]==str[j+1])j++;
        kmp[i]=j;
    }
    // string tail(str+kmp[t]+1);
    // string head(str+1);
    // head.erase(kmp[t]);
    // cout<<head;
    // while(n--){
    //     cout<<tail;
    // }cout<<endl;
    char tail[60]={0},head[60]={0};
    int lt=0,lh=0;
    for(int i=0;str[kmp[t]+1+i];i++){
        // cout<<kmp[t]+1<<endl;
        tail[i]=str[kmp[t]+1+i];
    }
    for(int i=0;i<kmp[t];i++){
        // cout<<kmp[t]<<endl;
        head[i]=str[i+1];
    }
    printf("%s",head);
    while(n--){
        printf("%s",tail);
    }cout<<endl;
    
}