#include<iostream>
#include<stdio.h>
using namespace std;
int ans;

void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[i] > sourceArr[j])
            {
                tempArr[k++] = sourceArr[j++];
                ans+=midIndex+1-i;
            }
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        {tempArr[k++] = sourceArr[i++];}
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = startIndex + (endIndex-startIndex) / 2;//避免溢出int
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

int main(){
    int cases;
    cin>>cases;
    for(int i=1;i<=cases;i++){
        int n;
        cin>>n;
        ans=0;
        int *sourceArr=new int [n];
        int *tempArr=new int [n];
        for(int i=0;i<n;i++){
            cin>>sourceArr[i];
        }
        MergeSort(sourceArr,tempArr,0,n-1);
        
        // for(int i=0;i<n;i++){
        //     cout<<sourceArr[i]<<" ";
        // }cout<<endl;

        printf("Scenario #%d:\n%d\n",i,ans);
    }
    return 0;
}