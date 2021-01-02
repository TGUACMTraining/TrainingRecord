#include<bits/stdc++.h>
using namespace std;
typedef struct {
    int f,j;
    double c;
}Room;
bool cmp(Room a,Room b){
    return a.c>b.c;
}
int main(){
    int m,n;
    while(1){
        cin>>m>>n;
        if(m==-1&&n==-1){
            break;
        }
        // Room room[1000];
        Room* room=new Room[n];
        for(int i=0;i<n;i++){
            cin>>room[i].j>>room[i].f;
            room[i].c=room[i].j*1.0/room[i].f;
        }
        sort(room,room+n,cmp);
        double javabeen=0;
        int p=0;
        while(m){
            if(room[p].f<=m){
                m-=room[p].f;
                javabeen+=room[p].j;
            }else{
                javabeen+=room[p].c*m;
                m=0;
            }
            p++;
        }
        printf("%.3f\n",javabeen);
    }
    return 0;
}