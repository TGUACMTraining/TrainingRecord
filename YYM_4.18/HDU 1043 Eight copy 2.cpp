#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<cstring>
#include<sstream>
using namespace std;
struct dot
{
    int x:4,y:4;
};
struct data{
    string state ;
    int from;
    char ope;
    dot E;
}q[(int)4e6];
bool visited[362879+10];
unordered_map<string,int>vis;
int head,tail;
int d[5]={0,1,0,-1,0};
char op[4]={'r','d','l','u'};
int bfs(){
    while(head!=tail){
        for(int i=0;i<4;i++){
            int x=q[tail].E.x+d[i];
            int y=q[tail].E.y+d[i+1];
            if(x>=0&&y>=0&&x<3&&y<3)
            {
                q[head].state=q[tail].state;

                swap(q[head].state[q[tail].E.x*3+q[tail].E.y],q[head].state[x*3+y]);
                if(visited[vis[q[head].state]])continue;
                visited[vis[q[head].state]]=true;
                q[head].from=tail;
                q[head].ope=i;
                q[head].E={x,y};
                if(q[head].state=="12345678x")return head;
                head++;
            }
        }tail++;
    }
    return 0;
}
char opes[(int)1e5];
int t;
int main(){
    int cnt=0;
    string s="12345678x";
    do{
        vis[s]=cnt++;
        
    }while(next_permutation(s.begin(),s.end()));
    int n;
    cin>>n;
    while (n--)
    {   
        head=tail=0;
        char c;
        memset(visited,0,sizeof(visited));
        q[head].ope=-1;
        q[head].state="";
        for(int i=0;i<9;i++){
            cin>>c;
            if(c=='x')q[head].E={i/3,i%3};
            q[head].state.push_back(c);
        }
        if(q[head].state=="12345678x"){cout<<" "<<endl;continue;}
        head++;
        int stop=bfs();
        t=0;
        // cout<<stop<<endl;
        for(int i=stop;i!=0;i=q[i].from){
            opes[t++]=q[i].ope;
        }
        // cout<<t<<endl;
        for(int i=t-1;i>=0;i--){
            cout<<op[opes[i]];
        }
        
        cout<<endl;
    }
    
}