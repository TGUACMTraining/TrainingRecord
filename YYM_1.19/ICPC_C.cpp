#include<iostream>
#include<stack>
using namespace std;
char table[3][3];
int check(char mod){
    if(table[0][0]==table[0][1]&&table[0][1]==table[0][2]&&table[0][2]==mod)return 1;
    if(table[1][0]==table[1][1]&&table[1][1]==table[1][2]&&table[1][2]==mod)return 1;
    if(table[2][0]==table[2][1]&&table[2][1]==table[2][2]&&table[2][2]==mod)return 1;
    if(table[0][0]==table[1][0]&&table[1][0]==table[2][0]&&table[2][0]==mod)return 1;
    if(table[0][1]==table[1][1]&&table[1][1]==table[2][1]&&table[2][1]==mod)return 1;
    if(table[0][2]==table[1][2]&&table[1][2]==table[2][2]&&table[2][2]==mod)return 1;
    if(table[0][0]==table[1][1]&&table[1][1]==table[2][2]&&table[2][2]==mod)return 1;
    if(table[2][0]==table[1][1]&&table[1][1]==table[0][2]&&table[0][2]==mod)return 1;
    return 0;    
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int x=0;
        int o=0;   
        stack<pair<int,int> >x_step;
        stack<pair<int,int> >o_step;
        int cache;
        memset(table,0,sizeof(table));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                scanf(" %c",&cache);
                switch(cache){
                    case 'X':x++; x_step.push(make_pair(i,j)); break;
                    case 'O':o++; o_step.push(make_pair(i,j)); break;
                }
            }
        }
        int empty=0;
        int per=0;
        while(1){
            if(!x_step.empty()&&!per){
                table[x_step.top().first][x_step.top().second]='X';
                x_step.pop();
                per=1;
            }else{
                break;
            }
            if(!o_step.empty()&&per){
                table[o_step.top().first][o_step.top().second]='O';
                o_step.pop();
                per=0;
            }else{
                break;
            }
        }
        if(x_step.empty()&&o_step.empty()&&(check('X')+check('O')!=2))cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}