#include <iostream>

using namespace std;
int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for(int i=s+1;i<=e; i++)
    {
        if(arr[i]<=pivot)
        {
            cnt++;
        }
    }
    
    int pivotindex = s + cnt;
    
    int temp = arr[pivotindex];
    
    arr[pivotindex] = arr[s];
    
    arr[s] = temp;
    
    int i = s, j = e;
    
    while(i < pivotindex && j > pivotindex)
    {
        while(arr[i] < pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }
        if(i < pivotindex && j > pivotindex)
        {
            int temp = arr[i++];
            arr[i++] = arr[j--];
            arr[j--] = temp;
            
        }
        
    }
    return pivotindex;
    
}
void quicksort(int arr[], int s, int e)
{
    if(s>=e)
    {
        return;
    }
    int p=partition(arr,s,e);
    
    quicksort(arr,s,p-1);
    
    quicksort(arr,p+1,e);
}
int main()
{
    int arr[10]={2,9,5,7,4};
    int n = 5;
    quicksort(arr,0,n-1);
    for(int i = 0;i < n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
