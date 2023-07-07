#include<iostream>
#include<limits.h>
using namespace std;
int largestrowsum(int arr[][3], int row, int  col)
{
    int maxi= INT_MIN;
    int rowindex=-1;
    for(row=0;row<3;row++)
    {
        int sum=0;
        for(col=0;col<3;col++)
        {
            sum=sum+arr[row][col];   
        }
        if(sum>maxi)
        {
            maxi=sum;
            rowindex=row;
        }
    }
    cout<<"the index of largest row sum is ";
    return rowindex;
}
int main()
{
    int arr[3][3];
    for(int row=0;row<3;row++)
    {
        for(int col=0; col<3;col++)
        {
            cin>>arr[row][col];
        }
    }
    
    for(int row=0;row<3;row++)
    {
        for(int col=0; col<3;col++)
        {
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    int ansindex= largestrowsum(arr,3,3);
    cout<<"max row sum is at index "<<ansindex<<endl;
}
