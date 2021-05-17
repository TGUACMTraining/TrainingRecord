#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
int n,m;
int a,b,c;
priority_queue<int>q;
void print(){
    if(!q.empty()){
        int t=q.top();
        q.pop();
        print();
        cout<<t<<" ";
    }
}
int main(){
    // freopen("a.in","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        for(int x=1;x<=m;x++){
            int t=a*x*x+b*x+c;
            if(!q.empty()&&t>q.top()&&q.size()==m)break;
            q.push(t);
            while(q.size()>m)q.pop();
        }
        ;
    }
    print();
}