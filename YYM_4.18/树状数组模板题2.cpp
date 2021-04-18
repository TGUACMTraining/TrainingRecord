#include<iostream>
using namespace std;
const int limit=(int)5.1e5;
int c[limit];
int n;
void add(int x,int k){
    for(;x<=n;x+=x&-x){
        c[x]+=k;
    }
}
int ask(int x){
    int ans=0;
    for(;x;x-=x&-x){
        ans+=c[x];
    }return ans;
}
int main(){
    int m;
    cin>>n;
    cin>>m;
    int cache=0;
    int now;
    for(int i=1;i<=n;i++){
        cin>>now;
        add(i,now-cache);
        cache=now;
    }
    int mode;
    while(m--){
        cin>>mode;
        switch (mode)
        {
        case 1:
            int l,r,k;
            cin>>l>>r>>k;
            add(l,k);
            add(r+1,-k);
            break;
        default:
            int x;
            cin>>x;
            cout<<ask(x)<<endl;
            break;
        }
    }
}