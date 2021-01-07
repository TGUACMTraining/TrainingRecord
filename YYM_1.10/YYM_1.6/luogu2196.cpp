#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=0;
    int connection[21][21]={0};
    cin>>n;
    int bomb[21];
    int max_bomb[21]={0};
    for(int i=1;i<=n;i++){
        cin>>bomb[i];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            cin>>connection[i][j];
        }
    }
    max_bomb[1]=bomb[1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(connection[j][i]){
                max_bomb[i]=max(max_bomb[i],max_bomb[j]);
            }
        }
        max_bomb[i]+=bomb[i];
    }
    int ans=0;
    int remain;
    for(int i=1;i<=n;i++){
        // ans=max(ans,max_bomb[i]);
        if(max_bomb[i]>ans){
            remain=i;
            ans=max_bomb[i];
        }
    }
    stack<int >step;
    step.push(remain);
    here:
        max_bomb[step.top()]-=bomb[step.top()];
        if(max_bomb[step.top()]){
            while(max_bomb[step.top()]!=max_bomb[--remain]);
            step.push(remain);
            goto here;
        }
    while(!step.empty()){
        cout<<step.top()<<" ";
        step.pop();
    }
    cout<<endl;
    cout<<ans;
    return 0;
}