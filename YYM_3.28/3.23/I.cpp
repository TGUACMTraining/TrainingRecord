#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    while (n--)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        cout<<(b+9-a)/10<<endl;
    }
    
}