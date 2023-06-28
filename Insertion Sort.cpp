#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    for(int i=0; i<n; i++)
    //while(i<n)
    {
        int  temp = arr[i];
        int j  = i-1;
        for(;j>=0;j--)
        //while(j<i-1)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }

        }
        //sort wala loop 0 se i-1 tak chlega harr i ke itteration k baad taki harr baar shuruat ke sabhi element compare ho jaye
        arr[j+1]=temp;
    }
}
