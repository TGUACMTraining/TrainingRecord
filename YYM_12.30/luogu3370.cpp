#include<set>
#include<functional>
#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string str;
    set<unsigned long long > s;
    hash<string> str_hash;
    for(int i=0;i<n;i++){
        cin>>str;
        s.insert(str_hash(str));
    }
    cout<<s.size()<<endl;
    return 0;
}