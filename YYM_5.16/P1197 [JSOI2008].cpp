#include<iostream>
#include<cstdio>
#include<list>
using namespace std;
int n,m;
const int limit=(int)2e5+10;
struct EDGE{
    int x,y;
}e[limit];
int lock[limit];
list<int>node[limit*2];
int father[limit*2];
int block;
int ff(int k){
    if(father[k]==k)return k;
    return father[k]=ff(father[k]);
}
void uni(int a,int b){
    if(ff(a)!=ff(b)){
        block--;
        father[ff(a)]=ff(b);
    }
}
EDGE se[limit];
int se_tail;
void pse(EDGE &E){
    se[se_tail++]=E;
}
int ans[limit];
int ans_tail;
void pans(){
    ans[ans_tail++]=block;
}
int k;
int attack[limit*2];
bool attacked[limit*2];
char *p;
inline void read(int &x){
    x=0;
    while(!isdigit(*p))p++;
    while(isdigit(*p))x=(x<<3)+(x<<1)+(*p++&15);
}
int main(){
    p=new char [(int)2e7];
    fread(p,1,(int)2e7,stdin);
    read(n);read(m);
    for(int i=0;i<n;i++){
        father[i]=i;
    }
    block=n;
    for(int i=0;i<m;i++){
        read(e[i].x);read(e[i].y);
        node[e[i].x].push_back(i);
        node[e[i].y].push_back(i);
    }
    read(k);
    for(int i=0;i<k;i++){
        read(attack[i]);
        attacked[attack[i]]=true;
        block--;
    }
    for(int i=0;i<n;i++){
        if(attacked[i])continue;
        int atk=i;
        for(int ind: node[atk]){
            lock[ind]++;
            if(lock[ind]==2)pse(e[ind]);
        }
        for(se_tail--;se_tail>=0;se_tail--){
            uni(se[se_tail].x,se[se_tail].y);
        }
        se_tail=0;
    }
    pans();
    for(k--;k>=0;k--){
        block++;
        int atk=attack[k];
        for(int ind: node[atk]){
            lock[ind]++;
            if(lock[ind]==2)pse(e[ind]);
        }
        for(se_tail--;se_tail>=0;se_tail--){
            uni(se[se_tail].x,se[se_tail].y);
        }
        se_tail=0;
        pans();
    }
    for(ans_tail--;ans_tail>=0;ans_tail--){
        printf("%d\n",ans[ans_tail]);
    }
}