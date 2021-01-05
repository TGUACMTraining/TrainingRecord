#include<iostream>
using namespace std;
typedef struct {
    char arr[500];
    int head=249;
    int tail=250;
    void phead(char c){
        arr[head--]=c;
    }
    void ptail(char c){
        arr[tail++]=c;
    }
    void insert(char c){
        int flag=0;
        for(int i=1;head+i<tail;i++){
            flag=arr[head+i]-c;
            if(flag)break;
        }
        if(flag>=0){
            phead(c);
        }else{
            ptail(c);
        }
    }
}strand;
int main(){
    int n;
    cin>>n;
    while(n--){
        string number_o;
        cin>>number_o;
        strand number_r;
        number_r.phead(number_o[0]);
        int stop;
        char min='9';
        for(int i=0;i<number_o.length();i++){
            if(number_o[i]!='0')
            {
                if(number_o[i]<min){
                    min=number_o[i];
                }
                if(min=='1'){break;}
            }
        }
        for(stop=number_o.length()-1;stop>=0;stop--){
            if(number_o[stop]==min){
                break;
            }
        }
        for(int i=1;i<stop;i++){
                number_r.insert(number_o[i]);
        }
        if(stop)
        number_r.phead(number_o[stop]);
        for(stop++;stop<number_o.length();stop++){
            number_r.ptail(number_o[stop]);
        }
        number_r.ptail(0);
        printf("%s\n",number_r.arr+number_r.head+1);
    }
}