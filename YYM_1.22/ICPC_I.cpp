#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct ints
{
    int index;
    int first;
    int second;
};
    bool cmp(const ints b,const ints a){
        if(b.first==a.first)return b.second>a.second;
        else return b.first>a.first;
    }

int main(){
    int N,K;
    cin>>N>>K;
    ints cow[50005];
    for(int i=0;i<N;i++){
        scanf("%d%d",&cow[i].first,&cow[i].second);
        cow[i].index=i;
    }
    nth_element(cow,cow+K-1,cow+N,cmp);
    int index=0;
    for(int i=0;i<K;i++){
        if(cow[index].second<cow[i].second)index=i;
    }
    cout<<cow[index].index+1;
}