#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#include<ctime>
#include<stack>
using namespace std;
const int limit=(int)1e4+10;
int father[limit];
int dis[limit];
int ret_dis(int child){
    if(dis[child])return dis[child];
    if(child==father[child]){dis[child]=1;return 1;}
    dis[child]=ret_dis(father[child])+1;
    father[child]=father[father[child]];
    return dis[child];
}
int father2[limit];
stack<int> res;
int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        father[i]=i;
    }
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        for(int j=0;j<t;j++){
            int child;
            cin>>child;
            father[child]=i;
        }
    }
    memcpy(father2,father,sizeof(father));
    int max_index;
    int cache=0;
    for(int i=0;i<n;i++){
        if(ret_dis(i)>cache){max_index=i;cache=ret_dis(i);}
        // cout<<ret_dis(i)<<" ";
        // cout<<"-------"<<endl;
    }
    res.push(max_index);
    while(res.top()!=father2[max_index]){
        res.push(father2[max_index]);
        max_index=father2[max_index];
    }cout<<res.size()<<endl;
    int flag=0;
    while(!res.empty()){
        if(flag)cout<<" ";
        flag=1;
        cout<<res.top();
        res.pop();
    }
}