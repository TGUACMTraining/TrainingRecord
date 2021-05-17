#include<iostream>
using namespace std;
long long n,h,r;
struct DOT
{
    long long x,y,z;
}dot[1020];
long long father[1020];
long long ff(long long k){
    if(k==father[k])return k;
    return father[k]=ff(father[k]);
}
void uni(long long a,long long b){
    if(ff(a)==ff(b))return ;
    long long dx=(dot[a].x-dot[b].x);
    long long dy=(dot[a].y-dot[b].y);
    long long dz=(dot[a].z-dot[b].z);
    if((dx*dx+dy*dy+dz*dz)<=4*r*r){
        father[ff(a)]=ff(b);
    }else if(dot[a].z<=r&&dot[b].z<=r){
        father[ff(a)]=ff(b);
    }else if(dot[a].z>=h-r&&dot[b].z>=h-r){
        father[ff(a)]=ff(b);
    }
}
bool jud(){
    long long up=-1;
    long long down=-1;
    for(long long i=0;i<n;i++){
        if(dot[i].z<=r)down=i;
        if(dot[i].z>=h-r)up=i;
    }
    if(up==-1||down==-1)return false;
    if(ff(up)==ff(down))return true;
    return false;
}
int main(){
    long long T;
    cin>>T;
    while(T--){
        cin>>n>>h>>r;
        for(long long i=0;i<1020;i++){
            father[i]=i;
        }        
        for(long long i=0;i<n;i++){
            cin>>dot[i].x>>dot[i].y>>dot[i].z;
        }
        for(long long i=0;i<n;i++){
            for(long long j=i+1;j<n;j++){
                uni(i,j);
            }
        }
        if(jud())cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}