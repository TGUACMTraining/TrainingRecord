#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(cin>>n,n){
        pair<int,int> *hotels=new pair<int,int> [n];
        for(int i=0;i<n;i++){
            cin>>hotels[i].first>>hotels[i].second;
        }
        sort(hotels,hotels+n);
        int numbers=1;
        int price=hotels->second;
        for(int i=1;i<n;i++){
            if(hotels[i].second<price){
                price=hotels[i].second;
                numbers++;
            }
        }
        cout<<numbers<<endl;
    }
}