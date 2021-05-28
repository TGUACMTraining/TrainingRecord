#include<iostream>
using namespace std;
typedef long long ll;
ll val[40];
int n;
bool visited[40][40];
ll Score[40][40];
int root[40][40];
ll score(int l,int r){
    if(l==r)return val[l];
    if(l+1==r)return val[l]+val[r];
    if(visited[l][r])return Score[l][r];
    visited[l][r]=true;
    int flag;
    for(int mid=l+1;mid<r;mid++){
        ll x=score(l,mid-1);
        x*=score(mid+1,r);
        x+=val[mid];
        if(x>Score[l][r]){
            Score[l][r]=x;
            flag=mid;
        }
    }
    root[l][r]=flag;
    return Score[l][r];
}
void print(int l,int r){
    if(l+1<r){
        cout<<root[l][r]<<" ";
        print(l,root[l][r]-1);
        print(root[l][r]+1,r);
    }else{
        if(l!=r)
        cout<<l<<" "<<r<<" ";
        else 
        cout<<l<<" ";
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    printf("%lld\n",score(1,n));
    print(1,n);
}