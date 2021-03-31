#include<iostream>
using namespace std;
long long gcd(long long a,long long b){
    if(b==0)return a;
    else return gcd (b,a%b);
}
long long gcdsum(long long a){
    long long cache=a,b;
    b=0;
        while (cache)
        {
            b+=cache%10;
            cache/=10;
        }
    return   gcd(a,b);
}
int main(){
    long long t;
    cin>>t;
    long long a,b;
    while(t--){
        cin>>a;
        a--;
        while (gcdsum(++a)==1);
        cout<<a<<endl;
    }
}