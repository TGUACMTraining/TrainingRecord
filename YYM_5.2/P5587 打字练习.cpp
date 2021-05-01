#include<string>
#include<iostream>
using namespace std;
string key[(int)1e4+5];
int key_tail;
string ans[(int)1e4+5];
int ans_tail;
int main(){
   
    string cache;
    while(getline(cin,cache),cache!="EOF"){
        for(char c:cache){
            if(c=='<'){
                if(key[key_tail].size()>=1)key[key_tail].pop_back();
            }else{
                key[key_tail].push_back(c);
            }
        }
        key_tail++;
    }
    while(getline(cin,cache),cache!="EOF"){
        for(char c:cache){
            if(c=='<'){
                if(ans[ans_tail].size()>=1)ans[ans_tail].pop_back();
            }else{
                ans[ans_tail].push_back(c);
            }
        }
        ans_tail++;
    }
    int n;
    cin>>n;
    int cnt=0;
    for(int i=0;i<key_tail;i++){
        int stop1=(key[i]).length();
        int stop2=(ans[i]).length();
        for(int j=0;j<stop1&&j<stop2;j++){
            if((key[i])[j]==(ans[i])[j])cnt++;
        }
    }
    double res=(cnt+0.0)*60/n;
    printf("%.0lf",res);
}