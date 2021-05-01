#include<iostream>
using namespace std;
int n;
int di[(int)1e5+10];
string name[(int)(1e5)+10];
int main(){
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>di[i]>>name[i];
        if(di[i]==0)di[i]=-1;
    }
    int finger=0;
    while(m--){
        int to;
        int step;
        cin>>to>>step;
        if(to==0)to=-1;
        int final_dir=1;
        switch (to*di[finger])
        {
        case 1:
            finger-=step%n;
            while(finger<0)finger+=n;
            break;
        
        default:
            finger+=step;
            finger%=n;
            break;
        }
    }
    cout<<name[finger];
}