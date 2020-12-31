#include<bits/stdc++.h>
using namespace std;
typedef struct{
    const int key=13;
    string str={""};
    vector <unsigned long long >str_hash={0};
    unsigned long long HASH(int begin){
        int length=str_hash.size();
        int to =str.length()-begin;
        int times=to - length+1;
        if(times>0){
            while(times--){
                str_hash.push_back((*(str_hash.end()-1))*key+(unsigned long long )str[str.length()-str_hash.size()]);
            }
            return (*(str_hash.end()-1));
        }
    }
    unsigned long long HASH(int begin,int L){
        unsigned long long ret=HASH(begin)-HASH(begin+L)*(unsigned long long)pow(key,L);
        return ret ;
    }
}my_string;
int main(){
    string str;
}