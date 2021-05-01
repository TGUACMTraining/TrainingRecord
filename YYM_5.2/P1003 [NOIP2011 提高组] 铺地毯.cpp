#include<iostream>
using namespace std;
int arr[(int)1e4][4];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
    }
    int x,y;
    cin>>x>>y;
    int res=-1;
    for(int i=1;i<=n;i++){
        if(x>=arr[i][0]&&x<=arr[i][0]+arr[i][2]&&y>=arr[i][1]&&y<=arr[i][1]+arr[i][3])res=i;
    }
    cout<<res;
}