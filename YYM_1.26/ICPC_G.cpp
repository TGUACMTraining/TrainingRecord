#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
struct table
{
    int time;
    bool open;
    bool operator<(table a){
        if(time==a.time){
            return open<a.open;
        }else{
            return time<a.time;
        }
    }
}tasks[200010];
int tail=0;
int main(){
    int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        int time=0;
        while(n--){
            scanf("%d%d",&tasks[tail].time,&tasks[tail+1].time);
            time+=tasks[tail+1].time-tasks[tail].time;
            tasks[tail].open=1;
            tasks[tail+1].open=0;
            tail+=2;
        }
        sort(tasks,tasks+tail);
        int num=0;
        stack<int >s;
        for(int i=0;i<tail;i++){
            if(tasks[i].open){
                if(!s.empty()){
                    time+=tasks[i].time-s.top();
                    s.pop();
                }else{
                    num++;
                }
            }else{
                s.push(tasks[i].time);
            }
        }
        cout<<num<<" "<<time<<endl;
    }
    
}