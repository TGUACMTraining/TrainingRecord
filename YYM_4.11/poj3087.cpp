#include<iostream>
#include<string>
#include<cstdio>
#include<map>
using namespace std;
string s1,s2;
string s;
map<string,bool> e;
int limit=0;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&limit);
        cin>>s1>>s2>>s;
        cout<<i<<" ";
        int times=0;
        int flag=1;
        while(++times)
        {   
            // cout<<endl;
            string shu;
            for(int i=0;i<limit;i++){
            shu.push_back(s2[i]);
            shu.push_back(s1[i]);
            }
            if(shu==s)break;
            if(e[shu]){
                flag=0;
                break;
            }
            e[shu]=true;
            for(int i=0;i<limit;i++){
                s1[i]=shu[i];
            }
            for(int i=0;i<limit;i++){
                s2[i]=shu[i+limit];
            }
            // cout<<shu<<endl;
        }
        if(flag){
            cout<<times<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
}