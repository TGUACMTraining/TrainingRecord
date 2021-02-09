#include<iostream>
using namespace std;
typedef long long ll;
ll m[105][105];
int main(){
    int cases;
    cin>>cases;
    for(int con=0;con<cases;con++){
        int n;
        int flag=1;
        scanf(" %*c %*c %d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>m[i][j];
                if(m[i][j]<0)flag=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(m[i][j]!=m[n+1-i][n+1-j]){flag=0;break;}
            }
            if(!flag)break;
        }
        if(flag)cout<<"Test #"<<con+1<<": Symmetric."<<endl;
        else cout<<"Test #"<<con+1<<": Non-symmetric."<<endl;
    }
}