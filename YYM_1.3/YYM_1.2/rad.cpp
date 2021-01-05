#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("test.out", "w", stdout);
    srand(time(NULL));
    int m=5;
    while(m--){
        int n=rand();
        n%=101;
        cout<<n<<endl;
        while(n--){
            flag:
            int a,b;
            a=rand()%25;
            b=rand()%25;
            if(a==b)goto flag;
            if(a>b)swap(a,b);
            cout<<a<<" "<<b<<endl;
        }
    }
    cout<<0<<endl;
    return 0;
}