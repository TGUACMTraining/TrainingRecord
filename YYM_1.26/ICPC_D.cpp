#include<iostream>
#include<string>
#include<map>
#include<list>
#include<algorithm>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        map<string,list<string> > dictionary;
        string cache_o,cache_s;
        while (n--)
        {
            cin>>cache_s;
            cache_o=cache_s;
            sort(cache_s.begin(),cache_s.end());
            dictionary[cache_s].push_back(cache_o);
        }
        while (cin>>cache_o,cache_o!="END")
        {
           cout<<"Anagrams for: "<<cache_o<<endl;
           cache_s=cache_o;
           sort(cache_s.begin(),cache_s.end());
           if(dictionary[cache_s].size()==0){
               cout<<"No anagrams for: "<<cache_o<<endl;
           }else{
               int i=0;
               for(string x:dictionary[cache_s]){
                   cout<<"  "<<++i<<") "<<x<<endl;
               }
           }
        }
        if(test)cout<<endl;
    }
}