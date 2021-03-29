#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char a[1100],b[1100];
int result[1100];
int main(){
    int t;
    cin>>t;
    int cnt=0;
    int flag=0;
    while(t--){
        if(flag)cout<<endl;
        flag=1;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(result,0,sizeof(result));
        printf("Case %d:\n",++cnt);
        scanf("%s%s",a,b);
        printf("%s + %s = ",a,b);
        int alen,blen;
        alen=strlen(a);
        blen=strlen(b);
        reverse(a,a+alen);
        reverse(b,b+blen);
        int len=max(alen,blen);
        for(int i=0;i<len;i++){
            if(a[i])a[i]-='0';
            if(b[i])b[i]-='0';
            result[i]=a[i]+b[i];
        }
        for(int i=0;i<len;i++){
            if(result[i]>=10){result[i+1]+=result[i]/10;result[i]%=10;}
        }int tail=1;
        for(int i=1099;i>0;i--){
            if(result[i]){tail=i+1;break;}
        }
        reverse(result,result+tail);
        for(int i=0;i<tail;i++){
            cout<<result[i];
        }cout<<endl;
    }
}