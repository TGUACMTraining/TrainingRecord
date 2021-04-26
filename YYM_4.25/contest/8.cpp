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
const int limit=1e3+20;
int arr[limit];
int tail;
int main(){
    int index=0;
    int n;
    cin>>arr[0]>>arr[1];
    cin>>n;
    tail=2;
    while(tail<n){
        int res=arr[index]*arr[index+1];
        if(res>=10){
            arr[tail++]=res/10;
            arr[tail++]=res%10;

        }else{
            arr[tail++]=res;
        }
        index++;
    }
    int flag=0;
    for(int i=0;i<n;i++){
        if(flag)cout<<" ";
        flag=1;
        cout<<arr[i];
        
    }
}