#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    sort(str.begin(),str.end());
    do{
        cout<<str<<endl;
    }while(next_permutation(str.begin(),str.end()));
    
}