#include<iostream>
#include<map>
#include<string>
#include<cstdio>
using namespace std;    
int main(){
    int n;
    map<string,int >book;
    string cache;
    string num;
    cin>>n;
    while(n--){
        cin>>cache;
        num="";
        for(int i=0;i<cache.size();i++){
            switch (cache[i])
            {
            case '1':
                num+='1';
                break;
            case 'A':
            case 'B':
            case 'C':
            case '2':
                num+='2';
                break;
            case 'D':
            case 'E':
            case 'F':
            case '3':
                num+='3';
                break;
            case 'G':
            case 'H':
            case 'I':
            case '4':
                num+='4';
                break;
            case 'J':
            case 'K':
            case 'L':
            case '5':
                num+='5';
                break;
            case 'M':
            case 'N':
            case 'O':
            case '6':
                num+='6';
                break;
            case 'P':
            case 'R':
            case 'S':
            case '7':
                num+='7';
                break;
            case 'T':
            case 'U':
            case 'V':
            case '8':
                num+='8';
                break;
            case 'W':
            case 'X':
            case 'Y':
            case '9':
                num+='9';
                break;
            case '0':
                num+='0';
                break;

            }
        }
        book[num]++;
    }
    int flag=1;
    
    for(map<string,int>::iterator index=book.begin();index!=book.end();index++){
        if((*index).second>1){
            flag=0;
            printf("%c%c%c-%c%c%c%c %d\n",(*index).first[0],(*index).first[1],(*index).first[2],(*index).first[3],(*index).first[4],(*index).first[5],(*index).first[6],(*index).second);
        }
    }
    if(flag){
        printf("No duplicates.\n");
    }
    return 0;
}