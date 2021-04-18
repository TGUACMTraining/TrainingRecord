#include<iostream>
#include<algorithm>
using namespace std;
int arr[9]={1,2,3,4,5,6,7,8,9};
int main(){
    int n;
    cin>>n;
    int cnt=0;
    do{
        for(int i=0;i<=7;i++){
            for(int j=i+1;j<9;j++){
                int l=0;
                for(int index=0;index<i;index++){
                    l*=10;
                    l+=arr[index];
                }
                if(l>=n)goto flag;
                int r=0;
                for(int index=j;index<9;index++){
                    r*=10;
                    r+=arr[index];
                }
                int m=0;
                for(int index=i;index<j;index++){
                    m*=10;
                    m+=arr[index];
                }
                if((n-l)*r==m){
                    cnt++;
                }
            }
        }
        flag:;
    }while(next_permutation(arr,arr+9));
    cout<<cnt<<endl;
}