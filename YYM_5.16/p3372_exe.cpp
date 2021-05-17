typedef long long ll;
const int limit=1e5+10;
struct segment_tree
{
    int tail;
    int arr[limit];
    int ans[limit<<2],lazy[limit<<2];
    int leftNode(int p){return p<<1;}
    int rightNode(int p){return p<<1|1;}
    void pushUp(int p){
        ans[p]=ans[leftNode(p)]+ans[rightNode(p)];
    }
    #define mmm int mid=(l+r)>>1
    void buildTree(int p,int l,int r){
        lazy[p]=0;
        if(l==r){
            ans[p]=arr[l];
            return ;
        }
        mmm;
        buildTree(leftNode(p),l,mid);
        buildTree(rightNode(p),mid+1,r);
        pushUp(p);
    }
    void f(int p,int l,int r,int k ){
        lazy[p]+=k;
        ans[p]+=k*(r-l+1);
    }
    void pushDown(int p,int l,int r){
        mmm;
        f(leftNode(p),l,mid,lazy[p]);
        f(rightNode(p),mid+1,r,lazy[p]);
        lazy[p]=0;
    }
    void rangeAdd(int al,int ar,int p,int l,int r,int k){
        if(l<=al&&ar<=r){
            f(p,l,r,k);
            return ;
        }
        //
        pushDown(p,l,r);
        mmm;
        if(l<=mid){rangeAdd(al,ar,leftNode(p),l,mid,k);}
        if(mid<r){rangeAdd(al,ar,rightNode(p),mid+1,r,k);}
        pushUp(p);
    }
    int ask(int al,int ar,int p,int l,int r){
        int result=0;
        if(l<=al&&ar<=r)return ans[p];
        mmm;
        pushDown(p,l,r);
        result+=(al<=mid?ask(al,ar,leftNode(p),l,mid):0);
        result+=(ar>mid?ask(al,ar,rightNode(p),mid+1,r):0);
        return result;
    }
};
