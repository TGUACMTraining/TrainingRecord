while(l<=r){
    int mid=(l+r)>>1;
    if(judge(mid)){
        ans=mid;
        l=mid+1;
    }
    else
    {
        r=mid-1;
    }
    
}return ans;