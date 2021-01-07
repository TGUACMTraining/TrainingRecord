#include<bits/stdc++.h>
using namespace std;
int n;
int max_bomb;
stack<int > step;
stack<int >ans;
int color[21];

int arr[21][21]={0};
int bomb[21];
int main(){
int search(int k);
memset(bomb,-1,sizeof(bomb));
    cin>>n;
    int cache;
    for(int i=1;i<=n;i++){
        cin>>bomb[i];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            cin>>cache;
            if(cache){
                arr[i][j]=arr[j][i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        step.push(i);
        color[i]=1;
        search(1);
        step.pop();
        color[i]=0;
    }
    cout<<max_bomb<<endl;
    stack<int >data;
    while(!ans.empty()){
        data.push(ans.top());
        ans.pop();
    }
    while(!data.empty()){
        cout<<data.top()<<" ";
        data.pop();
    }
    return 0;
}
int search(int k){
    int flag=0;
    for(int i=1;i<=n;i++){
        if(arr[step.top()][i]&&!color[i]){
            color[i]=1;
            step.push(i);
            flag=1;
            if(search(k+1)==0){
                stack<int>cache=step;
                int this_value=0;
                while(!cache.empty()){
                    this_value+=bomb[cache.top()];
                    cache.pop();
                }
                if(this_value>max_bomb){
                    max_bomb=this_value;
                    ans=step;
                }
            }
            color[i]=0;
            step.pop();
        }
    }
    return flag;
}