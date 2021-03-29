#include<iostream>
#include<set>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
        set <int>s;
        int num;
        while (n--)
        {
            cin>>num;
            s.insert(num);
        }
        while(m--){
            cin>>num;
            s.insert(num);
        }
        int flag=0;
        for(set<int>::iterator index=s.begin();index!=s.end();index++){
            if(flag)cout<<" ";
            flag=1;
            cout<<*index;
        }cout<<endl;
    }
}