#include<stdio.h>
typedef struct number{
    int a,b;
}NUM;
char cache[1000];
NUM read(){
    NUM ans;
    int i=0,flag=1;
    scanf("%s",cache);
    if(cache[i]=='-'){flag=-1;i++;}
    else flag=1;
    ans.a=0;
    ans.b=0;
    while(cache[i]>='0'&&cache[i]<='9')ans.a=ans.a*10+(cache[i++]&15);
    i++;
    while(cache[i]>='0'&&cache[i]<='9')ans.b=ans.b*10+(cache[i++]&15);
    ans.a*=flag;
    return ans;
}
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
NUM add(NUM x,NUM y){
    NUM ans;
    ans.a=x.a*y.b+x.b*y.a;
    ans.b=x.b*y.b;
    int g=1;
    if(ans.a&&ans.b)
    g=gcd(ans.a,ans.b);
    ans.a/=g;
    ans.b/=g;
    if(ans.b<0){ans.a*=-1;ans.b*=-1;}
    return ans;   
}
int main(){
    int n;
    NUM x=read();
    scanf("%d",&n);
    n--;
    while(n--){
        x=add(x,read());
    }
    printf("%d/%d\n",x.a,x.b);
}