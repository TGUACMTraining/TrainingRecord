#include<iostream>
using namespace std;
#define range 100000
bool IsPrime[range + 1];
void set() {
    int i, j;
    for (i = 0; i <= range; ++i)
        IsPrime[i] = true;
    IsPrime[0] = IsPrime[1] = false;
    for (i = 2; i <= range; ++i) {
        if (IsPrime[i]) {
            for (j = 2 * i; j <= range; j += i)
                IsPrime[j]=false;
        }
    }
}
int main(){
    int t;
    cin>>t;
    set();
    while(t--){
        int n;
        cin>>n;
        int a,b;
        int i=n;
        while(!IsPrime[++i]);
        a=i;
        i=i+n-1;
        while(!IsPrime[++i]);
        b=i;
        cout<<a*b<<endl;
    }

}