int n,a[500010],c[500010];long long ans;
void msort(int l,int r){ 
    if(l==r) return;
    int mid=(l+r)/2,i=l,j=mid+1,k=l;
    msort(l,mid),msort(mid+1,r);
    while(i<=mid&&j<=r)
    	if(a[i]<=a[j]) c[k++]=a[i++];
    	else c[k++]=a[j++],ans+=mid-i+1;
    while(i<=mid) c[k++]=a[i++];
    while(j<=r)   c[k++]=a[j++];
    for(int l=l;l<=r;l++) a[l]=c[l];
} 