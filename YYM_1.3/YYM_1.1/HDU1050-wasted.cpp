#include<bits/stdc++.h>
using namespace std;
struct Move{
    int from;
    int to;
};
int comefrom(list<Move> &plan,Move &step){
    list<Move>::iterator index=plan.begin();
    while(index!=plan.end()){
        if(!(step.from>(*index).to||step.to<(*index).from)){return 1;}
        index++;
    }
    return 0;
}
int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        cin>>n;
        list<Move> moves;
        Move cache;
        // Move *moves=new Move [n];
        for(int i=0;i<n;i++){
            cin>>cache.from>>cache.to;
            cache.from++;
            if(cache.to<cache.from)
            {
                swap(cache.to,cache.from);
            }
            moves.push_back(cache);
        }
        int time=0;
        while(!moves.empty()){
            list<Move> plan;
            for(list<Move>::iterator index=moves.begin();index!=moves.end();)
            {
                if(!comefrom(plan,(*index))){
                    plan.push_back((*index));
                    moves.erase(index++);
                }
                else{index++;}
            }        
            time++;
        }
        time*=10;
        cout<<time<<endl;
    }
    return 0;
}