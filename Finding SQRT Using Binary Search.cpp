#include <iostream>

using namespace std;

int sqrtbinary(int arr[], int n)
{
    int s = 0;
    int e = n;
    int ans = -1;
    int mid = s + (e - s)/2;
    while(s<=e)
    {
      int square = mid*mid;
      if(square == n)
      {
          return mid;
      }
      else if(square < n)
      {
          ans = mid;
          s = mid + 1;
      }
      else if(square > n)
      {
          e = mid - 1;
      }
      mid = s + (e - s)/2;
    }
    return ans;
    
}
int main()
{
      int arr[16]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}; 
      cout<< sqrtbinary(arr, 16);
}
