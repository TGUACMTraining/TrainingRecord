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
int arr[26];
int main(){

    for(int i=0;i<24;i++){
        cin>>arr[i];
    }
    int n;
    while(cin>>n){
        if(n<0||n>23)break;
        cout<<arr[n]<<" ";
        if(arr[n]>50){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}