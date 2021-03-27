#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    while(getline(cin,a),a!="#"){
        int sum=0;
        for(int i=0;i<a.length();i++){
            if(a[i]==' ')continue;
            sum+=(i+1)*(a[i]-'A'+1);
        }
        cout<<sum<<endl;
    }
}