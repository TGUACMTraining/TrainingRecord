#include<iostream>
#include<cstring>
using namespace std;
int arr[1024];
void j(int (&ar)[1024]){
    memset(ar,0,sizeof(ar));
}
int main(){
    memset(arr,1,sizeof(arr));
    j(arr);
    (int)arr;
    for(int i=0;i<10;i++){
        cout<<arr[i];
    }
}