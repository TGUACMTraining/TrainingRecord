#include <algorithm>
#include <bitset>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include<limits.h>
using namespace std;
#define refresh \
        cin>>psub>>ptime;\
        if(ptime){\
            ptime+=(psub-1)*20;\
            cache.solved++;\
            cache.times+=ptime;\
        }
struct team{
    string name;
    int solved;
    int times;
};
int cases(int a,int b){
    if(a==b)return 0;
    if(a>b)return 1;
    if(a<b)return -1;
}
team bigger(team &a,team &b){
    switch(cases(a.solved,b.solved)){
        case 0:
            switch(cases(a.times,b.times)){
                case 1:return b;
                case -1:return a;
                case 0:return a;
            }
        case 1:return a;
        case -1:return b;
    }
}
int main(){
    int n;
    cin>>n;
    team ans;
    ans.solved=0;
    ans.times=INT_MAX;
    int psub;
    int ptime;
    for(int i=0;i<n;i++){
        team cache;
        cache.solved=0;
        cache.times=0;
        cin>>cache.name;
        refresh
        refresh
        refresh
        refresh
        ans=bigger(ans,cache);
    }
    cout<<ans.name<<" "<<ans.solved<<" "<<ans.times<<endl;

}