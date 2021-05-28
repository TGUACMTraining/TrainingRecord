// #include <iostream>
// using namespace std;
// int main()
// {
//     int m, s, t;
//     cin >> m >> s >> t;
//     int s1 = 0, s2 = 0;
//     int tt = 0;
//     while (tt < t)
//     {
//         if (m >= 10)
//         {
//             m -= 10;
//             s2 += 60;
//         }
//         else
//         {
//             m += 4;
//         }
//         s1 += 17;
//         if (s2 > s1)
//             s1 = s2;
//         tt++;
//         if (s1 >= s)
//         {
//             cout << "Yes" << endl
//                  << tt;
//             return 0;
//         }
//     }cout<<"No"<<endl<<s1;
// }
#include<iostream>
using namespace std;
const int limit=5e7;
int magic[limit];
int t[limit];
int s[limit];
int tail;
int head;
int s_limit,t_limit;
int Time=-1;
int S=-1;
void push(int mm,int tt,int ss){
    magic[tail]=mm;
    t[tail]=tt;
    s[tail]=ss;
    if(ss>S){
        S=ss;
        Time=tt;
    }
    tail++;
    tail%=limit;
}
void pop(){
    head++;
    head%=limit;
}
int alive(){
    while(tail!=head){
        if(S>=s_limit){return true;}
        else if(t[head]>=t_limit){return false;}
        if(magic[head]>=10){
            push(magic[head]-10,t[head]+1,s[head]+60);
        }else if(t_limit-t[head]>10 &&s_limit-s[head]>=120){
            push(magic[head]+4,t[head]+1,s[head]);
        } else{
            push(magic[head]+4,t[head]+1,s[head]);
            push(magic[head],t[head]+1,s[head]+17);
        }pop();
    }
}
int main(){
    int m,s,t;
    scanf("%d%d%d",&m,&s,&t);
    s_limit=s;
    t_limit=t;
    push(m,0,0);
    if(alive()){
        printf("Yes\n%d",Time);
    }else{
        printf("No\n%d",S);
    }
}