#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        int *arr;
        cin>>n;
        arr=new int [n+1];
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        arr[0]=-1;
        sort(arr+1,arr+n+1);
        set<int> ele;
        int cache=arr[n];
        set<int >cache_;
        for(int i=n;i>0;i--){
            if(arr[i]!=arr[i-1]){
                if(!ele.count(arr[i]+1)){
                    arr[i]++;
                }
            }
            ele.insert(arr[i]);
        }
        cout<<ele.size()<<endl;
    }
    return 0;
}