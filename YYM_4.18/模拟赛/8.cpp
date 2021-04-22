#include<iostream>
using namespace std;
int arr[1010];
int main(){
    int n;
    cin>>n;
    while(n--){
        int id;
        int cg;
        scanf("%d%*C%*d%d",&id,&cg);
        arr[id]+=cg;
    }
    int max_id=0;
    for(int i=0;i<1001;i++){
        if(arr[i]>arr[max_id]){
            max_id=i;
        }
    }
    cout<<max_id<<" "<<arr[max_id];
}