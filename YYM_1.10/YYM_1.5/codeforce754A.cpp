#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int cnt=0;
    cin>>n;
    int *a=new int [n+1];
    int *b=new int [n+1]; 
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]){cnt++;}
    }
    if(cnt)
    {
        cout<<"YES"<<endl;
        cout<<cnt<<endl;
        int l=1;int r=1;
        while(cnt-1){
            cout<<l;
            cout<<" ";
            if(a[r])cout<<r;
            else{
                while(!a[++r]);
                cout<<r;
            }
            cout<<endl;
            l=r+1;
            r=l;
            cnt--;
        }
        cout<<l<<" "<<n<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}