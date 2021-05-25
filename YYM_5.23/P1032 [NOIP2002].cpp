#include<set>
#include<iostream>
#include<list>
#include<queue>
using namespace std;
list<pair<string,string>> tsfm;
string a,b;
queue<pair<string,int>>q;
string cache;
set<string> visited;
int bfs(){
    while(!q.empty()){
        if(q.front().first==b)return q.front().second;
        if(q.front().second==10){q.pop();continue;}
        string s=q.front().first;
        for(auto ts:tsfm){
            string &mod=ts.first;
            int pos=0;
            while((pos=s.find(mod,pos))!=-1) {
                cache=s.substr(0,pos);
                cache+=ts.second;
                if((pos)+ts.first.length()<s.length())
                cache+=s.substr((pos)+ts.first.length());
                if(!visited.count(cache))
                {
                    visited.insert(cache);
                    q.push({cache,q.front().second+1});
                }
                pos++;
            }
        }q.pop();
    }return -1;
}
int main(){
    string s1,s2;
    cin>>a>>b;
    while(cin>>s1>>s2){
        tsfm.push_back({s1,s2});
    }
    q.push({a,0});
    int ans;
    if((ans=bfs())!=-1) {
        cout<<ans<<endl;
    }else {
        cout<<"NO ANSWER!";
    }
}