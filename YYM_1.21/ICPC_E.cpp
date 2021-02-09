#include<iostream>
using namespace std;
typedef struct{
    int fav;
    int from;
} station;
int main(){
    int repeat;
    cin>>repeat;
    for(int a_number=1;a_number<=repeat;a_number++){
        int n;
        cin>>n;
        station *s=new station[n];
        s[0].fav=-1;
        int biggest=0;
        int fr=0;
        for(int i=1;i<n;i++){
            cin>>s[i].fav;
            if(s[i-1].fav>=0){
                s[i].fav+=s[i-1].fav;
                s[i].from=s[i-1].from;
            }else {
                s[i].from=i;
            }

            {
                cout<<"s[i].fav="<<s[i].fav<<",s[i].from="<<s[i].from<<endl;
            }


            if(fr!=s[i].from){
                if(s[i].fav>s[biggest].fav){
                    biggest=i;fr=s[i].from;
                }
            }else{
                if(s[i].fav>=s[biggest].fav){
                    biggest=i;
                }
            }
            
        }
        if(s[biggest].fav<0){
            printf("Route %d has no nice parts\n",a_number);
        }else{
            printf("The nicest part of route %d is between stops %d and %d\n",a_number,s[biggest].from,biggest+1);
        }
    }
    return 0;
}