#include<iostream>
using namespace std;
const int limit = (int )5.5e5;
int c[limit];
int n;
void add(int x,int k){
    for(;x<=n;x+=x&-x){
        c[x]+=k;
    }
}
int sum(int x){
    int s=0;
    for(;x;x-=x&-x){
        s+=c[x];
    }
    return s;
}
int main(){
    cin>>n;
    int m;
    cin>>m;
    for(int i=1;i<=n;i++){
        int cache;
        cin>>cache;
        add(i,cache);
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        switch (a)
        {
        case 1:
            add(b,c);
            break;
        
        default:
            cout<<sum(c)-sum(b-1)<<endl;
            break;
        }
    }
}