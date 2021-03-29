#include<iostream>
#include<cstring>
#include<set>
using namespace std;
int from[1200];
bool isself[1200];
int fr(int a){
    if(from[a]==a)return a;
    from[a]= fr(from[a]);
    return from[a];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            from[i]=i;
            isself[i]=false;
        }
        for(int i=0;i<m;i++){
            int a, b;
            cin>>a>>b;
            from[a]=b;
        }
        for(int i=1;i<=n;i++){
            isself[fr(i)]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(isself[i])ans++;
        }
        cout<<ans<<endl;
    }
}