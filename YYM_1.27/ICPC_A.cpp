#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cache;
    int _min=1e9+1;
    int _max=-_min;
    long long sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&cache);
        _max=max(_max,cache);
        _min=min(_min,cache);
        sum+=abs(cache);
    }
    if(_min>0){
        if(n>1)
        sum-=2*_min;
    }else if(_max<0){
        sum+=2*_max;
    }
    cout<<sum<<endl;
}