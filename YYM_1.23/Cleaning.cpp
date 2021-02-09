#include<iostream>
#include<algorithm>
using namespace std;
int arr[200005];
int n;
int tmp(){
    int to=arr[0];
    int flag=1;
    for(int i=1;i<n;i++){
        flag=-flag;
        to+=flag*arr[i];
    }   
    return to;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int flag=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int try_=tmp();
        if(try_){
            if(!(try_%2)){
                try_/=2;
                for(int i=1;i<n;i++){
                    try_=-try_;
                    if(arr[i]-arr[i-1]==try_){flag=1;break;}
                }
            }
            if(flag){
            cout<<"YES"<<endl;
            continue;
            }else{
            cout<<"NO"<<endl;
            continue;
            }
        }else{
            cout<<"YES"<<endl;
            continue;
        }
        
    }
    return 0;
    
}