#include<bits/stdc++.h>
using namespace std;
string str;
int ans;
int change2(int i);
int change3(int i);
int main(){
    int cases;
    cin>>cases;
    while (cases--)
    {
        ans=0;
        cin>>str;
        for(int i=0;i<str.length();i++){
            change2(i);
            change3(i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
int change2(int i){
    int begin=i;int end=i+1;
    if(end<str.length()){
        if(str[begin]==str[end])
        {
            if(str[begin]!='T'){
                str[end]='T';
                ans++;
            }
        }
    }
}
int change3(int i){
    int begin=i;int end=i+2;
    if(end<str.length()){
        if(str[begin]==str[end])
        {
            if(str[begin]!='T')
            {
                str[end]='T';
                ans++;
            }
        }
    }
}