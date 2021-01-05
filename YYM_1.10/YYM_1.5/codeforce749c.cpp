#include<bits/stdc++.h>
using namespace std;
int main(){
    list<char>strand;
    int kill_D,kill_R;
    int R_left,D_left;
    R_left=D_left=kill_D=kill_R=0;
    int length;
    cin>>length;
    char cache;
    for(int i=0;i<length;i++){
        cin>>cache;
        switch(cache){
            case 'D':D_left++;
            break;
            case 'R':R_left++;
            break;
        }
        strand.push_back(cache);
    }
    list<char>::iterator index=strand.begin();
    while(length-1&&D_left&&R_left){
        if(index==strand.end()){
            index=strand.begin();
        }
        if(kill_D&&*index=='D'){
            kill_D--;
            D_left--;
            strand.erase(index++);
            length--;
            continue;
        }
        if(kill_R&&*index=='R'){
            kill_R--;
            R_left--;
            strand.erase(index++);
            length--;
            continue;
        }
        switch(*index){
            case 'D':
                kill_R++;
                break;
            case 'R':
                kill_D++;
                break;
        }
        index++;
    }
    cout<<(*strand.begin())<<endl;
    return 0;
}