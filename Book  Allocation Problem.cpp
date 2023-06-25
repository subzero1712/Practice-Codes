#include <iostream>

using namespace std;

int ispossible(int arr[], int n, int m, int mid)
{
    int studcount = 0;
    int pagesum = 0;
    int i;
    
    for(i = 0; i <= n; i++)
    {
        if(pagesum + arr[i] <= mid){
        pagesum = pagesum + arr[i];
        }
    
    else
    {
        studcount++;
        if(studcount>m && arr[i]>mid)
        {
            return false;
        }
        pagesum =  arr[i];
    }
    
    }
    return true;
}

int alloctebooks(int arr[], int n, int m)
{
    int s = 0;
    int sum = 0;
    int ans = -1;
    int i;
    
    for(i = 0; i<=n; i++)
    {
        sum = sum + arr[i];
    }
    
    int e = sum;
    int mid = s + (e - s)/2;
    
    while(s<=e)
    {
        if(ispossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid -1;
        }
        else 
        {
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}
