#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
	int s = m + 1;
	int e = arr.size()-1;
        while (e>s) {
          
            swap(arr[s], arr[e]);

            s++;
            e--;
          
		 
        }
	
}
