#include <iostream>
using namespace std;
int jud[5][5] = {
    {0, -1, 1, 1, -1},
    {1, 0, -1, 1, -1},
    {-1, 1, 0, -1, 1},
    {-1, -1, 1, 0, 1},
    {1, 1, -1, -1, 0},
};
int a[210],ta;
int b[210],tb;
int main()
{
    int round;
    cin>>round>>ta>>tb;
    for(int i=0;i<ta;i++){
        cin>>a[i];
    }
    for(int j=0;j<tb;j++){
        cin>>b[j];
    }
    int resa=0,resb=0;
    for(int i=0;i<round;i++){
        switch (jud[a[i%ta]][b[i%tb]])
        {
        case 1:
            resa++;
            break;
        case -1:
            resb++;
            break;
        default:
            break;
        }
    }
    cout<<resa<<" "<<resb<<endl;
}