#include<iostream>
using namespace std;
int n;
string s[25];
int visited[25];
int ans;
int jud(int pre,int suf){
    for(int i=s[pre].length()-1;i;i--){
        for(int j=0;j<s[suf].length();j++){
            if(i+j==s[pre].length()){
                return i;
            }
            if(s[pre][i+j]!=s[suf][j]){
                break;
            }
        }
    }
    return 0;
}
void dfs( int pos,int length){
    ans=max(ans,length);
    for(int i=0;i<n;i++){
        if(visited[i]<2){
            int j=0;
            if(j=jud(pos,i)){
                visited[i]++;
                dfs( i,length+(s[i]).length()+j-(s[pos]).length());
                visited[i]--;
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    char c;
    cin>>c;
    for(int i=0;i<n;i++){
        if(c==s[i][0])
        {
            visited[i]++;
            dfs(i,(s[i]).length());
            visited[i]--;
        }
    }
    cout<<ans;
}