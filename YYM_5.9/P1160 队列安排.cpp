#include<iostream>
#include<list>
using namespace std;
int n;
list<int>stu;
list<int>::iterator stu_pos[(int)1e5+10];
bool rm[(int)1e5+10];
int main(){
    cin>>n;
    stu.push_back(1);
    stu_pos[1]=stu.begin();
    for(int i=2;i<=n;i++){
        int a,b;
        cin>>a>>b;
        auto p=stu_pos[a];
        switch (b)
        {
        case 0:
            stu_pos[i]= stu.insert(p,i);
            break;
        case 1:
            stu_pos[i]= stu.insert(++p,i);
            break;
        }
    }
    int m;
    cin>>m;
    while(m--){
        int t;
        cin>>t;
        rm[t]=true;
    }
    int flag=0;
    for(int t:stu){
        if(rm[t])continue;
        if(flag)cout<<" ";
        flag=1;
        cout<<t;
    }
    cout<<endl;
}