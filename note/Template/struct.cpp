#include<iostream>
using namespace std;
struct node{
    int x;
    int y;
    node(int _x=0,int _y=0){
        x=_x;
        y=_y;
    }
};
int main(){
node a=node(0);
node *b= new node(1,2);
}