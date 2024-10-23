#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
   int maxLen(vector<int> &arr, int n)
{
    int maxi = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (mp.find(sum) != mp.end())
        {
            maxi = max(maxi, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return maxi;
}
};
