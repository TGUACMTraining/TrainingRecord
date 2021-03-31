#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
list<pair<int,int> > w;
int cache[(int)1.2e5];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        int cnt=0;
        int remain;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>cache[i];
        }sort(cache,cache+n);
        w.push_back({cache[n-1],0});
        for(int i=n-1;i>=0;i--){
            if(cache[i]==w.back().first)
            w.back().second++;
            else w.push_back({cache[i],1});
        }
        while(!w.empty()){
        remain=m;
        for(list<pair<int,int> >::iterator index=w.begin();index!=w.end();index++){
            // cout<<(*index).first<<" @ "<<(*index).second<<" @ "<<remain<<endl;
            while((*index).first<=remain&&(*index).second>0){
            // cout<<(*index).first<<" # "<<(*index).second<<" # "<<remain<<endl;

                remain-=(*index).first;
                (*index).second--;
                if((*index).second==0){
                    index= w.erase(index);
                }
            }
        }
        cnt++;}
        cout<<cnt<<endl;
    }
    
}