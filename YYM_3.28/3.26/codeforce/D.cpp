#include<iostream>
#include<algorithm>
#include<stack>
#include<math.h>
#include<functional>
using namespace std;
int a[(int)2.2e5];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int cache=0;
        int last=a[0];
        stack<int>stk;
        for(int i=0;i<n;i++){
            if(a[i]==last){
                cache++;
            }else{
                last=a[i];
                stk.push(cache);
                cache=1;
            }
        }
        while(!stk.empty()){
            cache-=stk.top();
            stk.pop();
            cache=abs(cache);
        }
        cout<<cache<<endl;
    }
}