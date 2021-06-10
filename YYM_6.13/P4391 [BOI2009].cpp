#include<cstring>
#include<iostream>
using namespace std;
const int limit=1e6+10;
char r[limit];
int kmp[limit];
int rl;
int build(){
    int j=0;
    for(int i=2;i<=rl;i++){
        while(j&&r[j+1]!=r[i])j=kmp[j];
        if(r[i]==r[j+1])j++;
        kmp[i]=j;
    }
    return rl-kmp[rl];
}

int main(){
    scanf("%*d%s",r+1);
    rl=strlen(r+1);
    cout<<build();
}