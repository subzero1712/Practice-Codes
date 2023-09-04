#include <iostream>

using namespace std;
void merge(int arr[],int s,int e)
{
    int mid=s+(e-s)/2;
    
    int len1= mid-s+1;
    int len2= e-mid;
    
    int *first=new int[len1];
    int *second=new int[len2];
    
    int mainarray=s;
    for( int i=0; i<len1; i++)
    {
        first[i]=arr[mainarray++];
    }
    mainarray=mid + 1;
    for(int i=0;i<len2;i++)
    {
        second[i]=arr[mainarray++];
    }
    int index1=0;
    int index2=0;
    mainarray=s;
    while(index1<len1 && index2<len2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainarray++]=first[index1++];
        }
        else
        {
            arr[mainarray++]=second[index2++];
        }
    }
    while(index1<len1)
    {
        arr[mainarray++]=first[index1++];
    }
    while(index2<len2)
    {
        arr[mainarray++]=second[index2++];
    }
    delete []first;
    delete []second;
    
}
void mergesort(int arr[], int s, int e)
{
    int mid=s+(e-s)/2;
    //base case
    if(s>=e)
    {
        return ;
    }
    //left part sorting
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
    
}
int main()
{
    int arr[5]={8,6,4,90,432};
    mergesort(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}
