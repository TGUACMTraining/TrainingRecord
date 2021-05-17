#include<algorithm>
#include<iostream>
using namespace std;
struct event{
    int a,b;
    int imp;
}arr[(int)1e5+10];
int father[(int)4e4+20];
int n;
int ff(int k){
    if(k==father[k])return k;
    return father[k]=ff(father[k]);
}
bool cmp(event x,event y){
    return x.imp>y.imp;
}
int main(){
    for(int i=0;i<(int)4e4+10;i++){
        father[i]=i;
    }
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>arr[i].a>>arr[i].b>>arr[i].imp;
    }
    sort(arr,arr+m,cmp);
    int cli=0;
    for(int i=0;i<m;i++){
        if(ff(arr[i].a)!=ff(arr[i].b)){
            father[ff(arr[i].a)]=ff(arr[i].b+n);
            father[ff(arr[i].a+n)]=ff(arr[i].b);
        }else{
            cli=arr[i].imp;
            break;
        }
    }
    cout<<cli<<endl;
}