#include<cmath>
#include<iostream> 
using namespace std;
struct DOT{
    double x,y;
    int order;
    double r;
}dot[10];
int n;
int x,y,x_,y_;
#define mr(x) r=min(r,fabs(x));
inline double ds(int k,int m){
    return sqrt((dot[m].x-dot[k].x)*(dot[m].x-dot[k].x)+(dot[m].y-dot[k].y)*(dot[m].y-dot[k].y))-dot[m].r;
}
double getR(int k){
    DOT&d=dot[k];
    double r=fabs(d.x-x);
    mr(d.x-x_);
    mr(d.y-y);
    mr(d.y-y_);
    for(int i=0;i<n;i++){
        if(i==k)continue;
        if(dot[i].r<1e-6)continue;
        double t=ds(k,i);
        if(t<0)t=0;
        mr(t);
    }
    return r;
}
double ans=0;
void dfs(int k){
    if(k==n+1){
        double s=0;
        for(int i=0;i<n;i++){
            s+=dot[i].r*dot[i].r*acos(-1);
        }
        // for(int i=0;i<n;i++){
        //     printf("%d:%lf\n",dot[i].order,dot[i].r);
        // }cout<<s<<endl;
        // printf("%.0f\n",fabs((x-x_)*(y-y_))-s);
        // cout<<endl;

        ans=max(ans,s);
        return ;
    }
    for(int i=0;i<n;i++){
        if(dot[i].order==0){
            dot[i].order=k;
            dot[i].r=getR(i);
            dfs(k+1);
            dot[i].r=0;
            dot[i].order=0;
        }
    }
}
int main(){
    cin>>n;
    cin>>x>>y>>x_>>y_;
    for(int i=0;i<n;i++){
        cin>>dot[i].x>>dot[i].y;
    }
    dfs(1);
    printf("%.0f",fabs((x-x_)*(y-y_))-ans);
}