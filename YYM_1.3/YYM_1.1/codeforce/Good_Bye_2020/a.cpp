#include<set>
#include<iostream>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        int *arr;
        cin>>n;
        arr=new int [n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int cache=0;
        set<int> size;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cache=arr[j]-arr[i];
                size.insert(cache);
            }
        }
        cout<<size.size()<<endl;
    }
    return 0;
}