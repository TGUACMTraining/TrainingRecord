#include<bits/stdc++.h>
using namespace std;
int position[(unsigned long long)1e5];
int distance_[(unsigned long long)1e5];
int n,c;
int t;
int cut(int mid){
        int section=1;
        int room=0;
        for(int i=1;i<n;i++){
            room+=distance_[i];
            if(room>=mid){room=0;section++;}
        }
        return section;
}
int main(){
    cin>>t;
    while (t--)
    {
        cin>>n>>c;
        for(int i=0;i<n;i++){
            cin>>position[i];
        }
        sort(position,position+n);
        int l,r;
        l=INT_MAX;
        for(int i=1;i<n;i++){
            distance_[i]=position[i]-position[i-1];
            if(l>distance_[i])l=distance_[i];
        }
        r=position[n-1]-position[0];
        int cache=cut((l+r)/2);
        int flag;
        while(1){
            if(cache>c){l=(l+r)/2;}
            else if(cache<c){r=(l+r)/2;}
            else if(cache==c){flag=0;break;}
            if(l==r||r-l==1){flag=1;break;}
            cache=cut((l+r)/2);
        }
        if(flag){
            cache=cut(l);
            if(cache<c){
                while (cut(--l)<c);

            }
            else if(cache>c){
                while(cut(++l)>c);
                if(cut(l)<c)l--;
            }
            cout<<l;
        }else
        {
            l=(l+r)/2;
            while(cut(++l)==c);
            l--;
            cout<<l;
        }
        
    }
    return 0;
}
