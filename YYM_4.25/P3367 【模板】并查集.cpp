#include<iostream>
using namespace std;
const int limit =1e5+10;
int father[limit];
int findfather(int i){
    if(father[i]!=i)father[i]=findfather(father[i]);
    return father[i];
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
    int mode;
    while(m--){
        cin>>mode;
        int a,b;
        cin>>a>>b;
        switch (mode)
        {
        case 1:
            father[findfather(a)]=findfather(b);
            break;
        
        default:
            if(findfather(a)==findfather(b)){
                cout<<"Y"<<endl;
            }else cout<<"N"<<endl;
            break;
        }
    }
}