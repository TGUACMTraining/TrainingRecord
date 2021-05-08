#include<iostream>
#include<algorithm>
using namespace std;
int arr[(int)3e4+10];
bool visited[(int)3e4+10];
int n;
int limit;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    cin>>limit>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }sort(arr,arr+n,cmp);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(visited[i])continue;
        visited[i]=true;
        for(int j=i+1;j<n;j++){
            if(visited[j])continue;
            if(arr[i]+arr[j]<=limit){visited[j]=true;break;}
        }
        cnt++;
    }
    cout<<cnt<<endl;
}