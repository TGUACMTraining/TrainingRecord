#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while (n--)
    {
        int length;
        cin>>length;
        if(length==1){
            cout<<9<<endl;continue;
        }
        else{
            cout<<9;
            int cache=8;
            for(int i=1;i<length;i++){
                cout<<(cache++)%10;
            }cout<<endl;
        }
    }
    
}