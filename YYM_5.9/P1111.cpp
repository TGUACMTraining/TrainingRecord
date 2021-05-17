#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct ROAD{
    int x;
    int y;
    int t;
}roads[100000+10];
int father[1000+10];
bool cmp(ROAD a,ROAD b){
    return a.t<b.t;
}
int findfather(int k){
    if(k==father[k])return k;
    return father[k]=findfather(father[k]);
}
int uni(int a,int b){
    if(findfather(a)==findfather(b))return 0;
    father[findfather(a)]=father[findfather(b)];
    return 1;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        father[i]=i;
    }
    for(int i=0;i<m;i++){
        cin>>roads[i].x>>roads[i].y>>roads[i].t;
    }
    sort(roads,roads+m,cmp);
    int cnt=0;
    int i=0;
    for(;i<m;i++){
        cnt+=uni(roads[i].x,roads[i].y);
        if(cnt==n-1)break;
    }
    if(cnt==n-1)
    cout<<roads[i].t;
    else
    cout<<-1<<endl;
}