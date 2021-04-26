#include<iostream>
#include<algorithm>
using namespace std;
struct road{
    long long weight;
    long long x,y;
}roads[2100];
long long tail=0;
long long father[130];
bool xiao(road a,road b){
    return a.weight<b.weight;
}
long long n,m;
long long findfather(long long dot){
    if(dot==father[dot])return dot;
    else 
    return father[dot]=findfather(father[dot]);
}
void uni(long long x,long long y){
    father[findfather(x)]=findfather(y);
}
const long long mod=(long long)(1e9+7);
int main(){
    long long ans=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        father[i]=i;
    }
    while(m--){
        cin>>roads[tail].x>>roads[tail].y>>roads[tail].weight;
        tail++;
    }
    sort(roads,roads+tail,xiao);
    for(long long i=0;i<tail;i++){
        if(findfather(roads[i].x)!=findfather(roads[i].y)){
            ans+=roads[i].weight*500%mod;
            ans%=mod;
            uni(roads[i].x,roads[i].y);
        }
    }
    long long flag=1;
    long long father_=findfather(1);
    for(long long i=1;i<=n;i++){
        if(findfather(i)!=father_){
            flag=0;
            break;
        }
    }
    if(flag){
        cout<<ans<<endl;
    }else{
        cout<<"HuaiLiao."<<endl;
    }
}