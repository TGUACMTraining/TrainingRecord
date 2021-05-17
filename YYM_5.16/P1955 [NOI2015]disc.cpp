#include<iostream>
#include<algorithm>
using namespace std;
int father[(int)2e6+10];
pair<int,int> stk1[(int)2e6+10];
pair<int,int> stk2[(int)2e6+10];
int ind[(int)3e6+10];
int ti;
int ts1,ts2;
void clean(){
    ts1=ts2=ti=0;
    for(int i=0;i<(int)2e6;i++){
        father[i]=i;
    }
}
int ff(int n){
    int r=n;
    while(r!=father[r]){
        r=father[r];
    }
    for(int i=n,j;i!=r;i=j){
        j=father[i];
        father[i]=r;
    }
    return r;
}
void uni(int i,int j){
    if(i>j)father[ff(i)]=ff(j);
    else father[ff(j)]=ff(i);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        clean();
        int n;
        int i,j,e;
        cin>>n;
        while(n--){
            cin>>i>>j>>e;
            switch (e)
            {
            case 0:
                stk1[ts1++]={i,j};
                break;
            default:
                stk2[ts2++]={i,j};
                break;
            }
            ind[ti++]=i;
            ind[ti++]=j;
        }
        sort(ind,ind+ti);
        ti= unique(ind,ind+ti)-ind;
        for(int i=0;i<ts1;i++){
            stk1[i].first=lower_bound(ind,ind+ti,stk1[i].first)-ind;
            stk1[i].second=lower_bound(ind,ind+ti,stk1[i].second)-ind;
        }
        for(int i=0;i<ts2;i++){
            stk2[i].first=lower_bound(ind,ind+ti,stk2[i].first)-ind;
            stk2[i].second=lower_bound(ind,ind+ti,stk2[i].second)-ind;
        }
        
        for(int i=0;i<ts2;i++){
            uni(stk2[i].first,stk2[i].second);
        }
        int flag=1;
        for(int i=0;i<ts1;i++){
            if(ff(stk1[i].first)==ff(stk1[i].second)){
                flag=0;
                break;
            }
        }
        switch (flag)
        {
        case 1:
            cout<<"YES"<<endl;
            break;
        
        default:
            cout<<"NO"<<endl;
            break;
        }
    }   

}