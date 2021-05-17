#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
ll st[(int)2e5+10][30];
ll m,d;
ll t;
ll tail;
int main(){
    scanf("%lld",&m);scanf("%lld",&d);
    while(m--){
        char c;
        scanf(" %c",&c);
        ll l_n;
        scanf("%lld",&l_n);
        switch (c)
        {
        case 'A':
            st[tail++][0]=(l_n+t)%d;
            for(int i=1;i<30;i++){
                ll l=tail-(1ull<<i);
                if(l<0)break;
                st[l][i]=max(st[l][i-1],st[l+(1ull<<(i-1))][i-1]);
            }
            break;
        
        default:
            ll k=log2(l_n);
            int lim[2];
            lim[0]=tail-l_n;
            lim[1]=tail-1;
            printf("%lld\n",t=max(st[lim[0]][k],st[lim[1]+1-(1<<k)][k]));
            break;
        }
    }
}