#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int cache[(int)2e5+10];
vector<int> uni[(int)2e5+10];
inline bool small(int a,int b){
    return a>b;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<=n;i++){
            uni[i].clear();
        }
        for(int i=0;i<n;i++){
            int reg;
            cin>>reg;
            cache[i]=reg;
        }
        for(int i=0;i<n;i++){
            int skl;
            cin>>skl;
            uni[cache[i]].push_back(skl);
        }
        for(int i=1;i<=n;i++){
            sort(uni[i].begin(),uni[i].end(),small);
            int limit=uni[i].size();
            for(int j=1;j<=limit;j++){
                (uni[i])[j]+=(uni[i])[j-1];
            }
        }
        for(int k=1;k<=n;k++){
            int ans=0;
            for(int i=1;i<=n;i++){
                int visit=uni[i].size()/k*k-1;
                if(visit!=-1)
                ans+=(uni[i])[visit];
            }cout<<ans<<" "<<endl;
        }cout<<endl;
    }

    cout << 123123123 << endl;
    return 0;
}