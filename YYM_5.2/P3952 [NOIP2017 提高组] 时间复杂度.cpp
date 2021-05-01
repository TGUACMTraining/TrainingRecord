#include<iostream>
#include<cstring>
#include<unordered_set>
#include<string>
#include<sstream>
using namespace std;
unordered_set<char> var;
string alltext;
stringstream text;
int ERROR_CODE=0;
int jud(){
    string from,to;
    char va;
    {
        text>>va>>from>>to;
        if(var.count(va)){
            ERROR_CODE=1;
            return 0;
        }var.insert(va);
    }
    int total=0;
    int add=0;
    if(from=="n"){
        if(to!="n")
        {total=0;add=0;}
        else add=1;
    }
    else if(to!="n"){
        total=0;
        int l=0,r=0;
        for(char c:from){
            l*=10;
            l+=c-'0';
        }
        for(char c:to){
            r*=10;
            r+=c-'0';
        }
        if(l<=r){add=1;}
        else{add=0;}
    }else {
        total=1;
        add=1;
    }
    char cmd=0;
    
    int max_total=0;
    while(text>>cmd,cmd=='F'){
        max_total=max(max_total,jud());
    }
    if(add==1)total+=max_total;
    var.erase(va);
    return total;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int l;
        int o;
        ERROR_CODE=0;
        {
            string O;
            cin>>l>>O;
            if(O.length()==4){
                o=0;
            }else {
                o=0;
                int flag=0;
                for(int i=0;i<O.length();i++){
                    if(isdigit(O[i]))flag=1;
                    if(flag){
                        if(!isdigit(O[i])){break;}
                        o*=10;
                        o+=O[i]-'0';    
                    }
                }                
            }
        }
        int max_o=0;
        var.clear();
        alltext="";
        getchar();
        while(l--){
            string line;
            getline(cin,line);
            alltext+="\n"+line;
        }
        int fande=0;
        int vars=1;
        for(char c:alltext){
            if(c=='F')fande++;
            else if(c=='E')fande--;
            if(fande<0)break;
        }
        if(fande!=0){cout<<"ERR"<<endl;continue;}
        text.clear();
        text<<alltext;
        char cmd;

        while(text>>cmd){
            if(cmd=='F')
            max_o=max(jud(),max_o);
        }
        if(ERROR_CODE){cout<<"ERR"<<endl;continue;}
        if(max_o==o){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}