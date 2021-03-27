#include<iostream>
using namespace std;
void help(char c,int a,int b){
    if(a==b){
        a--;
        while(a--){
            cout<<" ";
        }
        cout<<c<<endl;
        return ;
    }
    int n=b-a;
    a--;
    while(a--) cout<<" ";
    cout<<c;
    n--;
    while(n--)cout<<" ";
    cout<<c<<endl;
}
void print(char c,int n){
    for(int i=0;i<n-1;i++){
        help(c,n-i,n+i);
    }
    for(int i=0;i<n*2-1;i++){
        cout<<c;
    }
    cout<<endl;
}
int main(){
    char a;
    int n;
    if(cin>>a,a!='@'){cin>>n;print(a,n);}
    while(cin>>a,a!='@'){
        cout<<endl;
        cin>>n;
        print(a,n);
    }
}