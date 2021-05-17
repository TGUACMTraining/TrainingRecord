#include<iostream>
#include<list>
#include<cmath>
using namespace std;
int pri(char c){
    switch (c)
    {
    case '+':
    case '-':
        return 0;
    case '*':
    case '/':
        return 1;
    case '^':
        return 2;    
    }
}
struct udf{
    int type;
    int num;
    char ope;
};
list<udf>s;
char ope[100];
int prio[100];
int tail;
void print(){
    for(udf t:s){
        switch (t.type)
        {
        case 0:
            cout<<t.num<<" ";
            break;
        
        default:
            cout<<t.ope<<" ";
            break;
        }
    }
    cout<<endl;
}
bool next_step(){
    auto ind=s.begin();
    while((*ind).type==0){ind++;if(ind==s.end())return false;}
    char ope=(*ind).ope;
    ind=s.erase(ind);
    int r=(*--ind).num;
    ind=s.erase(ind);
    int l=(*--ind).num;
    ind=s.erase(ind);
    auto k=[&]()->int{
        switch (ope)
        {
        case '+':
            return l+r;
        case '-':
            return l-r;
        case '*':
            return l*r;
        case '/':
            return l/r;
        case '^':
            return (int)(pow(l,r)+0.5);
        }
    };
    s.insert(ind,{0,k(),0});
    return true;
}
int main(){
    string o;
    cin>>o;
    int power=0;
    for(char x:o){
        if(isdigit(x)){s.push_back({0,x-'0',0});}
        else if(x=='(')power+=5;
        else if(x==')')power-=5;
        else {
            int p=power+pri(x);
            while(--tail,tail>=0&&prio[tail]>=p)s.push_back({1,0,ope[tail]});
            ope[++tail]=x;
            prio[tail++]=p;
        }
    }
    while(--tail,tail>=0)s.push_back({1,0,ope[tail]});
    do{
        print();
    }while(next_step());
}