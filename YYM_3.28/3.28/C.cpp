#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct student{
    string id;
    string name;
    int score;
};
student students[(int)1.2e5];
bool cmp_id(student a,student b){
    return a.id<b.id;
}
bool cmp_name(student a,student b){
    if(a.name==b.name)return a.id<b.id;
    return a.name<b.name;
}
bool cmp_score(student a,student b){
    if(a.score==b.score)return a.id<b.id;
    return a.score<b.score;
}
int main(){
    ios::sync_with_stdio(0);
    int N,C;
    int cnt=1;
    while(cin>>N>>C,N||C){
        for(int i=0;i<N;i++){
            cin>>students[i].id>>students[i].name>>students[i].score;
        }
        switch (C)
        {
        case 1:
            sort(students,students+N,cmp_id);
            break;
        case 2:
            sort(students,students+N,cmp_name);
            break;
        case 3:
            sort(students,students+N,cmp_score);
            break;
        }
        cout<<"Case "<<cnt++<<":"<<endl;
        for(int i=0;i<N;i++){
            cout<<students[i].id<<" "<<students[i].name<<" "<<students[i].score<<endl;
        }
    }
}