#include<iostream>
#include<cstring>
using namespace std;
int Rooms[(int)1e6+10];
int tmpdifRooms[(int)1e6+10];
int borrow[(int)1e6+10];
int l[(int)1e6+10];
int r[(int)1e6+10];
int n,m;
char *p;
const int caches_input=(int)1e6*20;
template<class T> inline void read(register T &x){
    x=0;
    while(!isdigit(*p))p++;
    while(isdigit(*p))x=x*10+(*p++&15);   
}
void go(int step){
    memset(tmpdifRooms,0,sizeof(tmpdifRooms));
    for(int i=0;i<=step;i++){
        tmpdifRooms[l[i]]+=borrow[i];
        tmpdifRooms[r[i]]-=borrow[i];
    }
}
bool judge(int step){
    go(step);
    int room=0;
    bool flag=true;
    for(int i=1;i<=n;i++){
        room+=tmpdifRooms[i];
        if(room>Rooms[i]){flag=false;goto ter;}
    }
    ter:;
    return flag;
}
int ask ()
{
    int first=0,last=m;
    while(first<last){
        int mid=(first+last)/2;
        if(judge(mid)){
            first=mid+1;
        }else{
            last=mid;
        }
    }
    return first;
}
int main(){
    p=new char[caches_input];
    fread(p,1,caches_input,stdin);
    read(n),read(m);
    for(int i=1;i<=n;i++){
        read(Rooms[i]);
    }
    for(int i=0;i<m;i++){
        read(borrow[i]);
        read(l[i]);read(r[i]);
        r[i]++;
    }
    int ans=ask();
    if(ans==m){
        cout<<0;
    }else{
        cout<<-1<<endl;
        cout<<ans+1;
    }
}