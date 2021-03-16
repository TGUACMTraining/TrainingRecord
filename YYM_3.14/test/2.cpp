#include<iostream>
#include<map>
#include<string>
#include<sstream>
using namespace std;
map<string,string>dic;
void solve(string a){
    if(dic[a]!=""){
        cout<<dic[a];
    }
    else{
        cout<<a;
    }
}
int main(){
    int n;
    cin>>n;
    while(n--){
        string cache_or,cache_ex;
        cin>>cache_or;
        getchar();
        getline(cin,cache_ex);
        dic[cache_or]=cache_ex;
    }
    cin>>n;
    getchar();
    string line;
    while(n--){
        getline(cin,line);
        stringstream cache;
        cache<<line;
        cache>>line;
        solve(line);
        while(cache>>line){
            cout<<" ";
            solve(line);
        }
        if(n)
        cout<<endl;
    }
}