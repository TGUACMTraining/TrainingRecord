#include<bits/stdc++.h>
using namespace std;
int main(){
    complex<int> a,b,c,d;
    complex<int> ab,bc,ca;
    int cache_1,cache_2;
        cin>>cache_1>>cache_2;
        a.real(cache_1);
        a.imag(cache_2);
        cin>>cache_1>>cache_2;
        b.real(cache_1);
        b.imag(cache_2);
        cin>>cache_1>>cache_2;
        c.real(cache_1);
        c.imag(cache_2);
        cout<<"3"<<endl;
    ab=b-a;
    bc=c-b;
    ca=a-c;
    d=a+bc;
    cout<<d.real()<<" "<<d.imag()<<endl;
    d=b+ca;
    cout<<d.real()<<" "<<d.imag()<<endl;
    d=c+ab;
    cout<<d.real()<<" "<<d.imag()<<endl;
    return 0;
}