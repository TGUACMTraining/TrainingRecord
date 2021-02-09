#include<iostream>
using namespace std;
struct point
{
    int x;
    int y;
    inline int cmp(int A,int B){
        int n = A*x+B*y;
        if(n==0)return 0;
        if(n>0)return 1;
        if(n<0)return -1;
    }
};

int main(){
    int n;
    while(cin>>n,n){
        point points[100]={0};
        int end=0;
        for(int i=0;i<2*n;i++){
            cin>>points[end].x>>points[end++].y;            
        }
        for(int A=-500;A<=500;A++){
            for(int B=-500;B<=500;B++){
                int cache=0;
                int judge;
                for(int i=0;i<end;i++){
                    judge=points[i].cmp(A,B);
                    if(judge)cache+=judge;
                    else break;
                }
                if(judge&&!cache){cout<<A<<" "<<B<<endl;goto ne;}
            }
        }
        ne:
            n=0;
    }
    return 0;
}