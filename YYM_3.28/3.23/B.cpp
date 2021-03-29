#include<bits/stdc++.h>
using namespace std;


int flag[10];
int main(){
    int n;
    cin>>n;
    getchar();
    
    while(n--){
        string str;
        getline(cin,str);
        for(int i=0;i<str.length();i++){
            if(str[i]!=' '){
                for(int j=i;j<=str.length();j++){
                    if(str[j]==' '||j==str.length()){
                        reverse(str.begin()+i,str.begin()+j);
                        i=j;
                        break;
                    }
                }
            }
        }
        cout<<str<<endl;
    }
}