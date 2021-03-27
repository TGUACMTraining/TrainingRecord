#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int ans=0;
        int n,k;
        string xs;
        cin>>n>>k>>xs;
        int first,last;
        for(int i=0;i<n;i++){
            if(xs[i]=='*'){
                first=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(xs[i]=='*'){
                last=i;
                break;
            }
        }
        int i=first-k;
        while(true){
            for(int j=k;j>0;j--){
                if(i+j>=last){
                    ans++;
                    goto flag;
                }
                if(xs[i+j]=='*'){
                    i=i+j;
                    ans++;
                    break;
                }
            }
        }
        flag:
        cout<<ans<<endl;
    }
    
}