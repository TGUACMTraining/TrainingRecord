#include<iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--)
    {
        long long  n,m,x;
        cin>>n>>m;
        cin>>x;
        x--;
        long long i,j;
        i=x%n;
        j=x/n;
        cout<<m*i+j+1<<endl;
    }
}