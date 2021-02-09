#include<iostream>
#include<vector>
using namespace std;
void so(vector<int > s);
int main(){
    int cache;
    while (1)
    {
        vector<int> s;
        while (cin>>cache,cache)
        {
            if(cache==-1)return 0;
            s.push_back(cache);
        }
        so(s);

    }
}
void so(vector<int > s){
    int ans=0;
    for(vector<int >::iterator i=s.begin();i!=s.end();i++){
        for(vector<int >::iterator j=i+1;j<s.end();j++){
            if(*i==*j*2||*i*2==*j)ans++;
        }
    }
    cout<<ans<<endl;
}