#include<iostream>
#include<map>
#include<list>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string strings[1005];
    int end=0;
    string cache;
    map<string,list<string> >_search;
    while (cin>>strings[end],strings[end]!="#"){
       cache=strings[end];
       for(int i=0;i<cache.size();i++){
           cache[i]=tolower(cache[i]);
       }
       sort(cache.begin(),cache.end());
       _search[cache].push_back(strings[end]);
    }
    ;
    for(map<string,list<string> >::iterator index=_search.begin();index!=_search.end();index++){
        if((*index).second.size()==1){
            cout<<*((*index).second.begin())<<endl;
        }
    }
    return 0;

}