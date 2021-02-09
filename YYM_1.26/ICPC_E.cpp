#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,q;
    int cnt=1;
    while (cin>>n>>q,n&&q)
    {
        cout<<"CASE# "<<cnt++<<":\n";
        vector<int >stone;
        while (n--)
        {
            int cache;
            cin>>cache;
            stone.push_back(cache);
        }
        sort(stone.begin(),stone.end());
        while(q--){
            int cache;
            cin>>cache;
            cout<<cache<<" ";
            vector<int >::iterator index=lower_bound(stone.begin(),stone.end(),cache);
            if(*index!=cache){
                cout<<"not found"<<endl;
            }
            else{
                cout<<"found at "<<index-stone.begin()+1<<endl;
            }
        }
    }
    
}