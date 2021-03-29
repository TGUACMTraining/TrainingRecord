#include<iostream>
#include<queue>
using namespace std;
bool visited[(int)1.2e5];
int cd (int mode,int at){
    switch(mode){
        case 1:
            return at+1;
        case 2:
            return at-1;
        case 0:
            return at*2;
    }
}
queue<pair<int,int> >q;

int main(){
    int a,b;
    cin>>a>>b;
    if(a>=b){cout<<a-b<<endl;return 0;}
    q.push({a,0});
    while(true){
        for(int i=0;i<3;i++){
            int next_point=cd(i,q.front().first);
            int next_step=q.front().second+1;
            if(next_point>0&&next_point<(int)1.2e5&&!visited[next_point])
            {
                // cout<<next_point<<" "<<next_step<<endl;
                q.push({next_point,next_step});
                visited[next_point]=true;
                if(next_point==b)goto flag;
            }
        }q.pop();
    }
    flag:
        cout<<q.back().second<<endl;
}