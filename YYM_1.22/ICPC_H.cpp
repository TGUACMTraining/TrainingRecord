#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct student
{
    char name[25];
    int score;
};
bool cmp(const student &a,const student &b){
    if(a.score==b.score){
        return strcmp(a.name,b.name);
    }
    return a.score>b.score;
    // return a.score>b.score;
}

int main(){
    int N,M,G;
    while(cin>>N,N){
        cin>>M>>G;
        int fenzhi[15];
        for(int i=1;i<=M;i++){
            scanf("%d",&fenzhi[i]);
        }
        student students[1005];
        for(int i=0;i<N;i++){
            scanf("%s",students[i].name);
            int solved;
            scanf("%d",&solved);
            int cache;
            students[i].score=0;
            // printf("%s\n",students[i].name);
            for(int j=0;j<solved;j++){
                cin>>cache;
                students[i].score+=fenzhi[cache];
                // cout<<students[i].score<<endl;
            }
            if(students[i].score<G){i--,N--;}
        }
        cout<<N<<endl;
        sort(students,students+N,cmp);
        for(int i=0;i<N;i++){
            printf("%s %d\n",students[i].name,students[i].score);
        }
    }
    return 0;
}