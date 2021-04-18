#include<iostream>
using namespace std;
struct change{
    int x,y;
};
change fun(int n,int i){
    int t=n/2;
    if(n==2){
        change arr[4]={{0,0},{0,1},{1,1},{1,0}};
        return arr[i];
    }
    change last=fun(n/2,i%(t*t));        
    switch (i/t/t)
    {
    case 0:
    return {last.y,last.x};
    case 1:
    return {last.x,last.y+t};
    case 2:
    return {last.x+t,last.y+t};
    case 3:
    return {n-1-last.y,t-1-last.x};
    }
    return {0,0};
}
int main(){
    int n,i;
    n=4;
    cin>>n>>i;
    change p=fun(n,i-1);
    cout<<p.x+1<<" "<<p.y+1<<endl;
}