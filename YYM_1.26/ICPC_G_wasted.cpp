#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        unordered_map<int,int>table;
        vector<pair<int,int> >tasks;
        int s,e;
        while(n--){
            scanf("%d%d",&s,&e);
            table[s]++;
            table[e+1]--;
        }
        unordered_map<int,int>::iterator index;
        
        // cout<<"loaded"<<endl;

        for(index=table.begin();index!=table.end();index++){
            tasks.push_back(*index);
            // cout<<index->first<<" "<<index->second<<endl;
        }
        sort(tasks.begin(),tasks.end());

        // cout<<"sort:"<<endl;
        // for(pair<int,int> a:tasks){
        //     cout<<a.first<<" "<<a.second<<endl;
        // }
        int n=0;
        int _max=0;
        for(pair<int,int>cache:tasks){
            n+=cache.second;
            _max=max(_max,n);
        }
        cout<<_max<<endl;
    }
}