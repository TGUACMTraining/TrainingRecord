#include<iostream>  
#include<vector>
#include<algorithm>
using namespace std;
int m,n;
int earn[110];
struct MINE{
    int st;
    int en;
    int val;
}mines[(int)1e4+10];
int val[15010];
vector<pair<int,int>>stm[(int)15010];
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>earn[i];
    }
    int stop=0;
    for(int i=0;i<n;i++){
        cin>>mines[i].st>>mines[i].en>>mines[i].val;
        mines[i].val=earn[mines[i].val];
        mines[i].val*=(mines[i].en-mines[i].st);
        stop=max(stop,mines[i].en);
    }
    for(int i=0;i<n;i++){
        stm[mines[i].en].push_back({mines[i].st,mines[i].val});
    }
    // for(int i=0;i<=stop;i++){
    //     cout<<i<<":"<<endl;
    //     for(auto p:stm[i]){
    //         cout<<p.first<<" "<<p.second<<endl;
    //     }cout<<endl;
    // }
    for(int t=0;t<stop+10;t++){
        auto index=stm[t].begin();
        for(;index!=stm[t].end();index++){
            val[t]=max(val[(*index).first]+(*index).second,val[t]);
        }
        val[t]=max(val[t],val[t-1]);
    }
    cout<<val[stop];
}