#include<queue>
#include<iostream>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,less<int>>l;
priority_queue<int,vector<int>,greater<int>>r;

int main(){
    int n;
    cin>>n;
    int a,b;
    cin>>a;
    r.push(a);
    cout<<r.top()<<endl;
    for(int i=1;i+1<n;i+=2){
        cin>>a>>b;
        r.push(a);
        l.push(b);
        while(l.top()>r.top()){
            l.push(r.top());
            r.push(l.top());
            l.pop(),r.pop();
        }
        cout<<r.top()<<endl;
    }
}