#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    while(N--){
        int L;
        cin>>L;
        int *arr=new int [L];
        for(int i=0;i<L;i++){
            cin>>arr[i];
        }
        int swaps=0;
        for(int i=0;i<L;i++){
            for(int j=L-1;j>i;j--){
                if(arr[j]<arr[j-1]){swap(arr[j],arr[j-1]);swaps++;}
            }
        }
        cout<<"Optimal train swapping takes "<<swaps<<" swaps."<<endl;
    }
}