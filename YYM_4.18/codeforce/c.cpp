#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int>ls;
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        ls.push_back(p);
    }
    for(int j=0;j<q;j++){
        int p;
        cin>>p;
        int cnt=0;
        for(auto index=ls.begin();index!=ls.end();index++){
            cnt++;
            if(*index==p){
                ls.erase(index);
                break;
            }
        }
        cout<<cnt<<" ";
        ls.push_front(p);
    }
}