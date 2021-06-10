void sort(int a[],int l,int r)
{
	if(l>=r)return;
	int i=l-1,j=r+1;
	int x=a[(l+r)/2];
	while(i<j)
	{
		i++,j--;
		while(a[i]<x)i++;
		while(a[j]>x)j--;
		if(i<j)
		{
			int m=a[i];
			a[i]=a[j];
			a[j]=m;
		}
	}
	sort(a,l,j);
	sort(a,j+1,r);
}









void sort(long* arr,int l,int r){
    if(l<r){
        if(r-l+1<10){
            InsertSort(arr,l,r);
            return;
        }
        int left=l,right=r;
        middle(arr,l,r,(l+r)>>1);
        long cache=arr[l];
        while(l<r){
            while(l<r&&arr[r]>=cache){
                r--;
            }
            arr[l]=arr[r];
            while(l<r&&arr[l]<=cache){
                l++;
            }
            arr[r]=arr[l];
        }
        arr[l]=cache;
        sort(arr,left,l-1);
        sort(arr,r+1,right);
    }
}

void middle(long*arr,long a,long b,long c){
    int p=(int)(arr[a]>=arr[b])<<2;
    p+=(int)(arr[b]>=arr[c])<<1;
    p+=(int)(arr[c]>=arr[a]);
    switch(p){
        int cache;
        case 5:
        case 2:
            return;
        case 1:
        case 6:
            cache=arr[a];
            arr[a]=arr[b];
            arr[b]=cache;
            return;
        case 3:
        case 4:
        case 7:
        case 0:
            cache=arr[a];
            arr[a]=arr[c];
            arr[c]=cache;
            return;
        
    }
}

void InsertSort(long arr[], int m, int n)
{
	int i, j;
	long temp; 
	for(i = m+1; i <= n; i++)
	{
		temp = arr[i];
		for(j = i-1; (j >= m)&&(arr[j] > temp); j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}
 