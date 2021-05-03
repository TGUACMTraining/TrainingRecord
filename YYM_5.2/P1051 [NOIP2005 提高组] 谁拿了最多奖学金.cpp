#include<string>
#include<iostream>
using namespace std;
string name[110];
int jiangjin[110];
int n;

int main(){
    cin>>n;
    int total=0;
    int jiangjinmax=0;
    int jiangjinmax_index;
    for(int i=0;i<n;i++){
        int qimopingjun,banjipingyi;
        char xueshengganbu,xibushengfenxuesheng;
        int lunwen;
        cin>>name[i]>>qimopingjun>>banjipingyi>>xueshengganbu>>xibushengfenxuesheng>>lunwen;
        if(qimopingjun>80&&lunwen>=1)jiangjin[i]+=8000;
        if(qimopingjun>85&&banjipingyi>80)jiangjin[i]+=4000;
        if(qimopingjun>90)jiangjin[i]+=2000;
        if(qimopingjun>85&&xibushengfenxuesheng=='Y')jiangjin[i]+=1000;
        if(banjipingyi>80&&xueshengganbu=='Y')jiangjin[i]+=850;
        if(jiangjin[i]>jiangjinmax){
            jiangjinmax=jiangjin[i];
            jiangjinmax_index=i;
        }
        total+=jiangjin[i];
    }
    cout<<name[jiangjinmax_index]<<endl;
    cout<<jiangjin[jiangjinmax_index]<<endl;
    cout<<total;
}