#include<iostream>
#include<cstring>
using namespace std;
const int limit=2e5+10;
char str[limit];
int mode[limit];
int lr[limit];
int lqm[limit];
int len;
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>str+1;
        len=strlen(str+1);
        for(int i=1;i<=len;i++){
            if(str[i]!='?')lqm[i]=0;
            else lqm[i]=lqm[i-1]+1;
            if((str[i]=='1'&&str[i-1]=='1')||(str[i]=='0'&&str[i-1]=='0')){
                lr[i]=1;
            }else if(str[i-1]==0){lr[i]=1;}
            else if(str[i]=='?')lr[i]=lr[i-1]+1;
            else if(str[i-1]=='?'){
                if(mode[i-1]==str[i]||mode[i-1]==0){
                    lr[i]=lr[i-1]+1;
                }else lr[i]=lqm[i-1]+1;
            }else lr[i]=lr[i-1]+1;
            if(str[i]=='?'){
                if(str[i-1]=='0'||str[i-1]=='1'||str[i-1]==0){
                    mode[i]=str[i-1];
                }else {
                    if(mode[i-1]=='0')mode[i]='1';
                    else if(mode[i-1]=='1')mode[i]='0';
                    else if(mode[i-1]==0)mode[i]=0;
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=len;i++){
            ans+=lr[i];
        }
        cout<<ans<<endl;
    }
}