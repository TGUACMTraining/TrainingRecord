#include<iostream>
#include<algorithm>
using namespace std;
struct st
{
    int number;
    int index;
};

bool cmp(st a,st b){
    return a.number<b.number;
}
int main(){
    int n,m;
    cin>>m>>n;
    char arr[105][105];
    char copy[105][105];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            copy[i][j]=arr[i][j];
        }
    }    
    st swaps[105]={0};
    for(int k=0;k<n;k++){
        swaps[k].index=k;
        swaps[k].number=0;
        for(int i=0;i<m;i++){
            for(int j=m-1;j>i;j--){
                if(copy[k][j]<copy[k][j-1]){swap(copy[k][j],copy[k][j-1]);swaps[k].number++;}
            }
        }
    }
    stable_sort(swaps,swaps+n,cmp);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        cout<<arr[swaps[i].index][j];
        }
        cout<<endl;
    }
}