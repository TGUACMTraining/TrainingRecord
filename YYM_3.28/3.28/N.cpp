#include<iostream>
#include<algorithm>
using namespace std;
int tail;
int arr[120];
int main(){
    while (cin>>tail,tail)
    {
        for(int i=0;i<tail;i++){
            cin>>arr[i];
        }
        sort(arr,arr+tail);
        cout<<arr[tail-1]<<endl;
    }
    
}