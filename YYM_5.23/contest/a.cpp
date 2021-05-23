#include<cmath>
#include<iostream>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long a,b;
        scanf("%lld%lld",&a,&b);
        if(a==0&&b==0){
            printf("NO\n");
        }else if(abs(a-b)<2){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}