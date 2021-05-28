#include<iostream>
#include<queue>
#include<vector>
using namespace std;
template <class _Ty, class _Container = vector<_Ty>, class _Pr = less<typename _Container::value_type>>
struct pq{
    priority_queue<_Ty,_Container,_Pr>q;
    priority_queue<_Ty,_Container,_Pr>del;
    void refresh(){
        while(!del.empty()&&del.top()==q.top()){
            del.pop();
            q.pop();
        }
    }
    void push(int val){
        q.push(val);
        refresh();
    }
    void pop(int val){
        del.push(val);
        refresh();
    }
    int top(){
        refresh();
        return q.top();
    }
};
pq<int,vector<int>,greater<int>>small;
pq<int,vector<int>,less<int>>big;

int arr[(int)1e6+10];
char *p;
inline void read(int &x){
    int flag=1;x=0;
    while(!isdigit(*p))(*p++)=='-'&&(flag=-1);
    while(isdigit(*p))x=(x<<3)+(x<<1)+(*p++&15);
    x*=flag;
}
int main(){
    p=new char [20*(int)1e6];
    fread(p,1,20*(int)1e6,stdin);

    int n;
    int k;
    // scanf("%d%d",&n,&k);
    read(n);read(k);
    for(register int i=0;i<n;++i){
        // scanf("%d",&arr[i]);
        read(arr[i]);
    }
    for(register int i=0;i<k;++i){
        big.push(arr[i]);
        small.push(arr[i]);
    }
    for(register int i=k;i<n;++i){
        printf("%d ",small.top());
        small.pop(arr[i-k]);
        small.push(arr[i]);
    }
    printf("%d\n",small.top());
    for(register int i=k;i<n;++i){
        printf("%d ",big.top());
        big.pop(arr[i-k]);
        big.push(arr[i]);
    }printf("%d\n",big.top());
}