#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while((cin>>n),n){
        int timetable[27]={0};//代表电视节目单的数组，下标表示节目开始时间，存的数是结束的时间，如果存的是0，就说明没有从这个时间开始的节目
        //例如一个从8点开始到10点结束的节目输入后，会看timetable[8]有没有更短的节目，如果没有，就存入10，
        //如果有更长时间的节目，比如原来存的12，那就会改为10，因为8到10点的节目显然比8到12点的节目更早结束
        int begin;
        int end;
        for(int i=0;i<n;i++){
            cin>>begin>>end;
            if(end==0)end=24;
            if(!timetable[begin]){//如果在这个时间原来还没有存入节目，那么就直接存入这个节目
                timetable[begin]=end;
            }else if(timetable[begin]>end){//看看是不是有时间更短的节目，如果没有，那么就改成当前的这个节目
                timetable[begin]=end;
            }
        }
        int cnt=0;//计数器
        int now=0;//代表当前时间
        for(int i=0;i<26;i++){//i代表要找节目的期限，设节目a点开始，b点结束，则b不能大于i；
            for(int j=now;j<i;j++){//设节目a点开始，b点结束，a应该不小与j
                if(timetable[j]&&timetable[j]<=i){
                    cnt++;//找到了符合条件的节目，计数器加一，更改现在的时间，并把原来的节目删掉(改为0)
                    now=timetable[j];
                    timetable[j]=0;
                    break;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
//我测了一百多组数据了（用随机数生成的）但是都与AC的代码结果相同，但是就是wrong answer。。