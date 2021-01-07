#include<bits/stdc++.h>
using namespace std;
const int limit=100010;
int main(){
    int n;
    cin>>n;
    int *arr1;
    int *arr2;
    arr1=new int [n+1]();
    arr2=new int [n+1]();
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>arr2[i];
    }
    int *cache =new int [n+1];
    int * mapping = new int [n+1];
    for(int i=1;i<=n;i++){
        mapping [arr1[i]]=i;
    }
    for(int i=1;i<=n;i++){
        arr2[i]=mapping[arr2[i]];
    }
    // {
    //     for(int i=1;i<=n;i++){
    //         cout<<arr2[i]<<"\t";
    //     }cout<<endl;
    // }
    int index_end=1;
    cache[1]=arr2[1];
    for(int i=1;i<=n;i++){
        if(arr2[i]>cache[index_end])cache[++index_end]=arr2[i];
        else
        {
            *upper_bound(cache+1,cache+index_end+1,arr2[i],less<int >())=arr2[i];
        }
    }
    cout<<index_end<<endl;
    return 0;
}