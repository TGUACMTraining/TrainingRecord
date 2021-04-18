#include<iostream>
using namespace std;
struct pots{
    int a,b;
};
int A,B,C;
bool visited[110][110];
pots q[11000];
int from[11000];
int ope[11000];
int head,tail;
enum{none,fill_a,fill_b,drop_a,drop_b,pour_a_b,pour_b_a};
int cnt;
bool push(pots p,int from_,int mode){
    if(visited[p.a][p.b])return false;
    q[head]=p;
    from[head]=from_;
    ope[head]=mode;
    visited[p.a][p.b]=true;
    head++;
    return p.a==C||p.b==C;
}
pots go(pots p,int mode){
    switch (mode)
    {
    case fill_a:
        return {A,p.b};
    case fill_b:
        return {p.a,B};
    case drop_a:
        return {0,p.b};
    case drop_b:
        return {p.a,0};
    case pour_a_b:
        if(B-p.b>=p.a){
            return {0,p.a+p.b};
        }else return{p.a+p.b-B,B};
    case pour_b_a:
        if(A-p.a>=p.b){
            return {p.a+p.b,0};
        }else return{A,p.b+p.a-A};
    }
    return {0,0};
}
bool bfs(){
    while(head!=tail){
        for(int i=1;i<7;i++){
            if(push(go(q[tail],i),tail,i)){
                return true;
            }
        }
        tail++;   
    }
    return false;
}
int st[11000];
int main(){
    cin>>A>>B>>C;
    push({0,0},0,none);
    if(bfs()){
        for(int i=head-1;i!=0;i=from[i]){
            st[++st[0]]=i;
            
        }
        cout<<st[0]<<endl;
        for(int i=st[0];i>0;i--){
            switch (ope[st[i]])
            {
            case 1:
                cout<<"FILL(1)";
                break;
            case 2:
                cout<<"FILL(2)";
                break;
            case 3:
                cout<<"DROP(1)";
                break;
            case 4:
                cout<<"DROP(2)";
                break;
            case 5:
                cout<<"POUR(1,2)";
                break;
            case 6:
                cout<<"POUR(2,1)";
                break;
            }
            cout<<endl;
        }
    }else{
        cout<<"impossible"<<endl;
    }
}