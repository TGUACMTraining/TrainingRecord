bool f(int x){return true;}
int main(){
    int l,r;
    while(l<r){
        int mid=(l+r)>>1;
        if(f(mid)) l=mid+1;//排除mid是答案的可能
        else r=mid;
    }
    while(l<r){
        int mid=(l+r+1)>>1;
        if(f(mid)) r=mid-1;//排除mid是答案的可能
        else l=mid;
    }
}