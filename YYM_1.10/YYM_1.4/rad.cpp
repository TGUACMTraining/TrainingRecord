#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("test.out", "w", stdout);
    srand(time(NULL));
    int m=5;
    cout<<5<<endl;
    while(m--){
        int n=rand();
        n%=101;
        while(n--){
            int i=rand()%10;
            cout<<i;
        }cout<<endl;
    }
    return 0;
}