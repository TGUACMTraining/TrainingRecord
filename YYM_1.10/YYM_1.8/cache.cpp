#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("test.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=20;i++){
        for(int j=1;j<=2222;j++){
            printf("%5d\t",i*j);
        }
        cout<<endl;
    }
}