#include<iostream>
#include<cmath>
using namespace std;
int n,m,c,t;
const double pi=3.1415926;
double solve(int cases){
    switch (cases)
    {
    case 2:
        return c*(t-c)*(2*n*m-n-m);
    case 5:
        return c*(c/2)*(2*n+2*m-4);
    case 4:
        return (n-1)*(m-1)*pi*c*c/4;
    case 3:
        return (n-1)*(m-1)*c*c*(1-pi/4);
    case 1:
        return m*n*t*t-solve(2)-solve(3)-solve(4)-solve(5);
    }
}
int main(){
    int cases;
    cin>>cases;
    for(int i=1;i<=cases;i++){
    cin>>m>>n>>t>>c;
    cout<<"Case "<<cases<<":"<<endl;
    printf("Probability of covering 1 tile  = %.4f%%\n",solve(1)*100/m/n/t/t);
    printf("Probability of covering 2 tile  = %.4f%%\n",(solve(2)+solve(5))*100/m/n/t/t);
    printf("Probability of covering 3 tile  = %.4f%%\n",solve(3)*100/m/n/t/t);
    printf("Probability of covering 4 tile  = %.4f%%\n",solve(4)*100/m/n/t/t);
    }

}