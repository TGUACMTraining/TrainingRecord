#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int vct[10][3]={
    {0,0,0},
    {1,2,3},
    {10,11,13},
    {100,101,103},
    {1000,1009,1013},
    {10000,10007,10009},
    {100000,100003,100019},
    {1000000,1000003,1000033},
    {10000000,10000019,10000079},
    {100000000,(int)1e8+7,(int)1e8+9},
};
int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        a-=(c-1);
        b-=(c-1);
        cout<<vct[a][1]*vct[c][0]<<" "<<vct[b][2]*vct[c][0];
        cout<<endl;
    }
}