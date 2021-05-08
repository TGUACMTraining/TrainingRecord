#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;
const int limit=100000;
int arr[limit+10];
int main(){
    int t=clock();
    for(int i=1;i<=limit;i++){
        arr[i]=i;
    }
    while(next_permutation(arr+1,arr+limit+1));
    cout<<clock()-t<<endl;
}