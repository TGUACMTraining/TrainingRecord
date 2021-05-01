#include <iostream>
using namespace std;
int solves[210][210][210]; //number,max,split
int main()
{
    for(int i=0;i<210;i++){
        solves[0][i][0]=1;
    }

    for (int i = 1; i < 210; i++)
    {
        for (int j = 1; j <210; j++)
        {
            if(j<=i)
            for (int k = 1; k <= i; k++)
            {
                solves[i][j][k] = solves[i][j - 1][k] + solves[i - j][j][k - 1];
            }
            else{
                for (int k = 1; k <= i; k++)
                    solves[i][j][k]=solves[i][j-1][k];
            }
        }
    }
    int n,k;
    cin>>n>>k;
    cout<<solves[n][n][k]<<endl;
}