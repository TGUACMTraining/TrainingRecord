    #include<iostream>
    #include<queue>
    #include<vector>
    #include<cstring>
    using namespace std;
    typedef pair<int,int> pii;
    int t,n;
    const int limit=1e3+10;
    priority_queue<pii,vector<pii>,greater<pii> >q;
    vector<pii> next_way[limit];
    int dis[limit];
    int poped[limit];
    void bfs(){
        while(!q.empty()){
            int node=q.top().second;
            q.pop();
            if(poped[node])continue;
            poped[node]=1;
            for(int a=next_way[node].size()-1;a>=0;a--){
                if(dis[(next_way[node])[a].second]>(next_way[node])[a].first+dis[node]){
                    dis[(next_way[node])[a].second]=(next_way[node])[a].first+dis[node];
                    q.push({dis[(next_way[node])[a].second],(next_way[node])[a].second});
                }
            }
        }
    }
    int main(){
        cin>>t>>n;
        memset(dis,0x3f,sizeof(dis));
        while(t--){
            int from,to,cost;
            cin>>from>>to>>cost;
            next_way[from].push_back({cost,to});
            next_way[to].push_back({cost,from});
        }
        dis[n]=0;
        q.push({0,n});
        bfs();
        cout<<dis[1]<<endl;
        return 0;
    }