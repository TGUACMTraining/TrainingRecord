#include<iostream>
using namespace std;
const int limit=(int)5e4+10;
int f[limit*3];
int n,k;
int ans=0;
int ff(int k){
    if(k==f[k])return k;
    return f[k]=ff(f[k]);
}
bool eq(int x,int y){
    if(ff(x)==ff(y))return true;return false;
}
bool xRy(int x,int y){
    if(ff(x)==ff(y+n))return true;return false;
}
int main(){
    for(int i=0;i<3*limit;i++){
        f[i]=i;
    }
    cin>>n>>k;
    while(k--){
        int mode,x,y;
        cin>>mode>>x>>y;
        if(x>n||y>n){
            ans++;
            continue;
        }
        switch (mode)
        {
        case 1:
            if(!xRy(x,y)&&!xRy(y,x)){
                for(int i=0;i<3;i++){
                    f[ff(x+i*n)]=ff(y+i*n);
                }
            }else ans++;
            break;
        
        default:
            if(!eq(x,y)&&!xRy(y,x)){
                for(int i=0;i<3;i++){
                    int si,si1;
                    si=i*n;
                    si1=(i+1)%3*n;
                    f[ff(x+si)]=ff(y+si1);
                }
            }else ans++;
            break;
        }
    }
    cout<<ans;
}