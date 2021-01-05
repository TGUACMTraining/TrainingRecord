#include<iostream>
using namespace std;
typedef struct {
    char arr[300];
    int head=149;
    int tail=150;
    void phead(char c){
        arr[head--]=c;
    }
    void ptail(char c){
        arr[tail++]=c;
    }
    void insert(char c){
        int flag=0;
        for(int i=1;head+i<tail;i++){
            if(arr[head+i]=='0')continue;
            flag=arr[head+i]-c;
            if(flag)break;
        }
        if(flag>=0){
            phead(c);
        }else if(flag<0){
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
        for(int i=1;i<number_o.length();i++){
            if(number_o[i]=='0'){
                int flag=1;
                char judge=number_r.arr[number_r.head+1];
                for(int j=i+1;j<number_o.length();j++){
                    flag=number_o[j]-judge;
                    if(flag<=0&&number_o[j]!='0'){
                        break;
                    }
                }
                if(flag<=0){
                    number_r.phead(number_o[i]);
                }
                else{
                    number_r.ptail(number_o[i]);
                }
            }
            else{
                number_r.insert(number_o[i]);
            }
        }
        number_r.ptail(0);
        printf("%s\n",number_r.arr+number_r.head+1);
    }
}