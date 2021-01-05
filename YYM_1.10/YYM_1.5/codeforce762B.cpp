#include<bits/stdc++.h>
using namespace std;
int main(){
    enum{usb,ps2,both};
    int computer[3]={0};
    int number=0;
    long long cost=0;
    priority_queue<int,vector<int >,greater<int> > mouse[2];
    int n;
    for(int i=0;i<3;i++){
        cin>>computer[i];
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int cache;
        char p[10];
        scanf("%d %s",&cache,p);
        switch(p[0]){
            case 'U':
                (mouse[usb]).push(cache);
                break;
            case 'P':
                (mouse[ps2]).push(cache);
                break;
        }
    }
    while (computer[usb]--)
    {
        if((mouse[usb]).empty()){break;}
        else{number++;cost+=(mouse[usb]).top();(mouse[usb]).pop();}
    }
    while (computer[ps2]--)
    {
        if((mouse[ps2]).empty()){break;}
        else{number++;cost+=(mouse[ps2]).top();(mouse[ps2]).pop();}
    }
    while(!(mouse[ps2]).empty()){
        (mouse[usb]).push((mouse[ps2]).top());
        (mouse[ps2]).pop();
    }
    while(computer[both]--){
        if((mouse[usb]).empty()){break;}
        else{number++;cost+=(mouse[usb]).top();(mouse[usb]).pop();}
    }
    cout<<number<<" "<<cost<<endl;
    return 0;
    
}