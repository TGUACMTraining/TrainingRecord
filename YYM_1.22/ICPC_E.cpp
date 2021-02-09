#include<iostream>
// #include<functional>
#include<string>
#include<algorithm>
using namespace std;
#define dbg(x) \
{\
cout<<"line "<<__LINE__<<":"<<endl;\
    x;\
cout<<"end "<<__LINE__<<endl;\
}
#ifndef dbg
#define dbg(x)
#endif

struct string_with_cache
{
    string str;
    string cache;
};
bool cmp(const string_with_cache&a,const string_with_cache&b){
    return a.cache<b.cache;
}
struct com{    
    bool operator()(const string_with_cache &a,const string_with_cache &b){
        return a.cache<b.cache;
    }
};
int main(){
    string_with_cache arr[105];
    int end=0;
    string cache;
    while(cin>>cache,cache!=(string)"XXXXXX"){
        arr[end].str=cache;
        stable_sort(cache.begin(),cache.end());
        arr[end++].cache=cache;
    }
    sort(arr,arr+end,cmp);
    while(cin>>cache,cache!=(string)"XXXXXX"){
        sort(cache.begin(),cache.end());
        string_with_cache var;
        var.cache=cache;
        string_with_cache* begin_=lower_bound(arr,arr+end,var,com());
        string_with_cache* end_=upper_bound(arr,arr+end,var,com());
        if(begin_==end_){cout<<"NOT A VALID WORD"<<endl;}
        for(;begin_<end_;begin_++){
            cout<<begin_->str<<endl;
        }
        cout<<"******"<<endl;
    }
}