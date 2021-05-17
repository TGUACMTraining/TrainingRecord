#include<iostream>
#include<algorithm>
using namespace std;
struct JOB{
    long long ddl;
    long long val;
}job[(int)1e5+10];
bool cmp(JOB a,JOB b){
    if(a.ddl==b.ddl)return a.val>b.val;
    return a.ddl<b.ddl;
}
long long n;
main(){
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>job[i].ddl>>job[i].val;
    }
    sort(job,job+n,cmp);
    long long time=-1;
    long long ans=0;
    for(long long i=0;i<n;i++){
        if(job[i].ddl!=time){
            ans+=job[i].val;
            time=job[i].ddl;
        }
    }
    cout<<ans<<endl;

}