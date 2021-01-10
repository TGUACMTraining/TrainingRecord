#include<bits/stdc++.h>
using namespace std;
// #define len_ 
#define len_ (long long )3e5+10
int sgn(long long  x){
    if(x==0)return 0;
    else return x/abs(x);
}
int main(){
    int n;
    cin>>n;
    while (n--)
    {
        static int a[len_];
        static int change[len_];
        int  intimidation_value=0;
        int length;
        cin>>length;
        cin>>a[0];
        for(int i=1;i<length;i++){
            cin>>a[i];
            change[i]=sgn(a[i]-a[i-1]);
        }
        int cancel=0;
        int cache=0;
        for(int i=1;i<length-1;i++){
            if(change[i]*change[i+1]<0){intimidation_value++;cache++;}
            else cache=0;
            cancel=max(cancel,cache);
        }
        intimidation_value-=min(3,cancel);
        if(intimidation_value<0){intimidation_value=0;}
        cout<<intimidation_value<<endl;
    }
    return 0;
}