#include<iostream> 
using namespace std;
int k;
const int limit=3e5;
char result[limit];
char tree[limit];
int ans[limit];
int tail;
int P(int t){
    return 1<<t;
}
void rev(){
    tail=1;
    for(int i=k;i;i--){
        for(int j=P(k-i-1)+1;j<=P(k-i);j++){
            tree[tail++]=result[j];
        }
    }
}
int main(){
    scanf("%d",&k);
    
}