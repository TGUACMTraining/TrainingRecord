#include<bits/stdc++.h>
using namespace std;


int flag[10];
int main(){
    int n;
    cin>>n;
    getchar();
    
    while(n--){
        stringstream ss;
        string cen;
        getline(cin,cen);
        ss<<cen;
        while(ss>>cen){
            for(int i=cen.length()-1;i>=0;i--){
                cout<<cen[i];
            }
            if(flag[0])
            cout<<" ";
            flag[0]=1;
        }
        if(flag[1])
        cout<<endl;
        flag[1]=1;
    }
}