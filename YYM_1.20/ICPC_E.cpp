#include<cstdio>
#include<iostream>
#include<limits.h>
using namespace std;
// #define debug
#ifdef debug
#define dbg(x)                                           \
    {                                                    \
        cout << "In line " << __LINE__ << endl;          \
        x                                                \
        cout << "-----------------" << __LINE__ << endl; \
    }
#else
#define dbg(x)
#endif
typedef long long ll;
ll toll(string str,ll b,ll e){
    ll ans=0;
    for(;b!=e;b++){
        ans*=10;
        ans+=str[b]-'0';
    }
    return ans;
}
ll gcd(ll a,ll b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
struct fraction
{
    ll fz;
    ll fm;

    inline void sim(){
        ll t=gcd(fz,fm);
        fz/=t,fm/=t;
    }
    fraction operator+(fraction t){
        fraction m;
        m.fz=fz*t.fm+t.fz*fm;
        m.fm=fm*t.fm;
        sim();
        return m;
    }
};
ll f_pow(ll a,ll i){
  if (i==0) return 1;
  ll temp=f_pow(a,i>>1);
  temp=temp*temp;
  if (i&1) temp=(ll)temp*a;
  return temp;
}
ll creat9[]={1,9,99,999,9999,99999,999999,9999999,99999999,999999999};
int main(){
    string str;
    while (cin>>str,str!="0")
    {
        ll n=str.length()-5;
        fraction cache;
        cache.fm=INT_MAX;
        for(ll i=0;i<n;i++){
            fraction left;
            left.fz=toll(str,2,2+i);
            left.fm=f_pow(10,i);
            fraction right;
            right.fz=toll(str,2+i,str.length()-3);
            right.fm=creat9[str.length()-3-2-i]*f_pow(10,n-1);
            dbg(
                printf("%d/%d %d/%d\n",left.fz,left.fm,right.fz,right.fm);
            )
            left.sim();
            right.sim();
            left=left+right;
            dbg(
                cout<<"s-"<<left.fz<<"/"<<left.fm<<endl;
            )
            left.sim();
            if(left.fm<cache.fm)cache=left;
            dbg(
                cout<<"ans "<<cache.fz<<"/"<<cache.fm<<endl;
            )
        }
        cout<<cache.fz<<"/"<<cache.fm<<endl;
    }
    return 0;
}