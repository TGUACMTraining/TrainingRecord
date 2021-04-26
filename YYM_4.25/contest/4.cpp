#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#include<ctime>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    while(n--){
        double cache;
        cin>>cache;
        if(cache<m){
            printf("On Sale! %.1lf\n",cache);
        }
    }
}