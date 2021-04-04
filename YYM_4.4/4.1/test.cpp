#include<iostream>
#include<map>
#include<sstream>
using namespace std;
int arr[(int)6.3e5];
int mod=10000;
int main(){
    map<string,pair<bool,int> >m;
    arr[0]=arr[1]=arr[2]=1;
    int l,r;
    string key;
    for(int i=3;i<6.3e5;i++){
        stringstream ss;
        arr[i]=(arr[i-1]+arr[i-2]+arr[i-3])%mod;
        ss<<arr[i-1]<<arr[i-2]<<arr[i-3];
        ss>>key;
        if(m[key].first){r=i;l=m[key].second;break;}
        m[key]={true,i};
    }
    for(int i=0;i<r;i++){
        cout<<arr[i]<<endl;
    }

}