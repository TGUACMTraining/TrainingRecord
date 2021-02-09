#include<iostream>
#include<set>
#include<string>
#include<sstream>
using namespace std;
int main(){
    set<string> dictionary;
    string cache;
    string cache_;
    while (cin>>cache)
    {
        for(int i=0;i<cache.size();i++){
            if(cache[i]>='A'&&cache[i]<='Z')cache[i]=tolower(cache[i]);
            else if(!isalpha(cache[i]))cache[i]=' ';
        }
        stringstream ss;
        ss<<cache;
        while (ss>>cache)
        {
            dictionary.insert(cache);
        }
    }
    set<string>::iterator index;
    for(index=dictionary.begin();index!=dictionary.end();index++){
        cout<<*index<<endl;
    }    
}