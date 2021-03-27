#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    while(cin>>n,n){
        int cnt=0;
        vector<pair<int,int> >table;
        for(int i=0;i<n;i++){
            pair<int,int> a;
            cin>>a.second>>a.first;
            table.push_back(a);
        }
        sort(table.begin(),table.end());
        int now=0;
        for(int i=0;i<table.size();i++){
            if(table[i].second>=now){now=table[i].first;cnt++;}
        }
        cout<<cnt<<endl;
    }
}