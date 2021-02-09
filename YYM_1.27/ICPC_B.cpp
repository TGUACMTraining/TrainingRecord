#include<iostream>
#include<cstring>
using namespace std;
int begin_end[26][26];
int main(){
    int n;
    cin>>n;
    {
        while(n--){
            char cache[15];
            scanf("%s",cache);
            int len=strlen(cache);
            int head=cache[0]-'a';
            int tail=cache[len-1]-'a';
            begin_end[head][tail]=max(begin_end[head][tail],len);
            for(int i=0;i<26;i++){
                if(begin_end[i][head]){
                    begin_end[i][tail]=max(begin_end[i][head]+len,begin_end[i][tail]);
                }
            }
            if((head==tail)){
                begin_end[head][tail]-=len;
            }
        }
        int max_length=0;
        for(int i=0;i<26;i++){
            max_length=max(begin_end[i][i],max_length);
        }
        cout<<max_length<<endl;
    }
}